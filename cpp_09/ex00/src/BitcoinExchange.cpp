#include	<iostream>
#include	<string>
#include	<fstream>
#include	<cstdlib>
#include	<map>
#include	"../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _dbLoaded(false)
{
	#ifdef DEBUG
	std::cout << "[CONSTRUCTOR]\tcalled." << std::endl;
	#endif

	_dbLoaded = loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	#ifdef DEBUG
	std::cout << "[COPY CONSTRUCTOR]\tcalled." << std::endl;
	#endif

	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &input)
{
	#ifdef DEBUG
	std::cout << "[COPY A.OPER.]\tcalled." << std::endl;
	#endif

	if (this != &input)
		_data = input._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	#ifdef DEBUG
	std::cout << "[DESTRUCTOR]\tcalled." << std::endl;
	#endif
}

//	trims content removing whitespaces, tabs and any CR/LF left by the line ending
static	std::string	trim(const std::string &inputStr)
{
	size_t	start;
	size_t	end;

	start = inputStr.find_first_not_of(" \t\r\n");
	end = inputStr.find_last_not_of(" \t\r\n");

	//	if string doesn't contain other characters than whitespace
	if (start == std::string::npos)
		return ("");

	return (inputStr.substr(start, end - start + 1));
}

//	verifies a value is written as a plain decimal number
//	(guards against strtod extras: hex "0x10", exponents "1e2", "inf", "nan")
static	bool	isPlainNumber(const std::string &valueStr)
{
	size_t	i;
	size_t	dots;
	bool	digitFound;

	i = 0;
	dots = 0;
	digitFound = false;

	if (i < valueStr.size() && (valueStr[i] == '+' || valueStr[i] == '-'))
		i++;

	while (i < valueStr.size())
	{
		if (isdigit(static_cast<unsigned char>(valueStr[i])))
			digitFound = true;
		else if (valueStr[i] == '.')
			dots++;
		else
			return (false);
		i++;
	}
	if (!digitFound || dots > 1)
		return (false);
	return (true);
}


// splits, trims and stores key and value from the input string
//	trimming here (not in the caller) keeps the invariant that every
//	fragment is already normalized before any validation runs
bool	BitcoinExchange::splitLine(const std::string &line, std::string &dateStr, std::string &valueStr)
{
	size_t	position;

	position = line.find('|');

	if(position == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	dateStr = trim(line.substr(0, position));
	valueStr = trim(line.substr(position + 1));

	#ifdef DEBUG
	std::cout << "[SPLITLINE]\t" << "date: [" << dateStr << "] value: [" << valueStr << "]" << std::endl;
	#endif

	return (true);
}

// converts date str into int and verifies if the date is in the calendar
static bool	convertYear(const std::string &dateStr)
{
	int	year;
	int	month;
	int	day;

	year =	std::atoi(dateStr.substr(0, 4).c_str());
	month =	std::atoi(dateStr.substr(5, 2).c_str());
	day =	std::atoi(dateStr.substr(8, 2).c_str());
	
	if (month < 1 || month > 12)
		return (false);

	int	monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	maxDays = monthDays[month - 1];

	if (month == 2 && ((year % 4 == 0 && year %100 != 0) || year %400 == 0))
		maxDays = 29;

	if (day < 1 || day > maxDays)
		return (false);

	return (true);
}

// verifies the format of the date str
bool	BitcoinExchange::validateDate(const std::string &dateStr)
{
	if(dateStr.size() != 10)
		return (false);

	if(dateStr[4] != '-' || dateStr[7] != '-')
		return (false);
	
	int	i = 0;
	
	while (i < 10)
	{
		if (i == 4 || i == 7)
		{
			i++;
			continue ;
		}
		if (!isdigit(static_cast<unsigned char>(dateStr[i])))
			return (false);
		i++;
	}
	if(!convertYear(dateStr))
		return (false);

	return (true);
}

// verifies the value str is a plain number in range and returns error if not
bool	BitcoinExchange::validateValue(const std::string &valueStr)
{
	char	*lastChar;
	double	value;

	if (!isPlainNumber(valueStr))
	{
		std::cerr << "Error: not a valid number." << std::endl;
		return (false);
	}

	value = std::strtod(valueStr.c_str(), &lastChar);

	if (*lastChar != '\0')
	{
		std::cerr << "Error: not a valid number." << std::endl;
		return (false);
	}
	//	NaN compares false against everything, so it would slip past both
	//	range checks below and print as "nan" - test it explicitly
	if (value != value)
	{
		std::cerr << "Error: not a valid number." << std::endl;
		return (false);
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

// compares input to our _data(base)
double	BitcoinExchange::getRate(const std::string &dateStr)
{
	std::map<std::string, double>::iterator it = _data.lower_bound(dateStr);

	if (it == _data.end() || it ->first != dateStr)
	{
		if (it == _data.begin())
		{
			throw std::exception();
		}
		--it;
	}
	return (it->second);
}

// loads the "data.csv" file that is our database for comparison
bool	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());

	if(!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return (false);
	}

	std::string	line;
	std::getline(file, line);	// skip headerline ("data" | "exchange value")

	while (std::getline(file, line))
	{
		size_t	position = line.find(',');

		if (position == std::string::npos)
			continue ;

		//	keys are trimmed exactly like the input side is, otherwise a
		//	stray space ("2011-01-09 ,0.32") stores a key that can never
		//	be matched and the lookup silently falls back to a stale rate
		std::string	dateStr = trim(line.substr(0, position));
		std::string	rateStr = trim(line.substr(position + 1));
	
		if (!validateDate(dateStr))
		{
			std::cerr << "Error: bad database entry => " << line << std::endl;
			continue ;
		}
	
		double	rate = std::strtod(rateStr.c_str(), NULL);
	
		_data[dateStr] = rate;

		#ifdef DEBUG
		std::cout << "[LOADDATABASE]\t" << "date: [" << dateStr << "] rate: [" << rateStr << "]" << std::endl;
		#endif

	}
	if (_data.empty())
	{
		std::cerr << "Error: database is empty." << std::endl;
		return (false);
	}
	#ifdef DEBUG
	std::cerr << "[LOADDATABASE]\tentries loaded: " << _data.size() << std::endl;
	#endif
	return (true);
}

bool	BitcoinExchange::isDatabaseLoaded() const
{
	return (_dbLoaded);
}

//	opens inputfile and parses it
bool	BitcoinExchange::parseInputFile(const std::string& inputFilename)
{
	//	opens the file, ifstream can't read strings so c_str converts the string to const char*
	std::ifstream	file(inputFilename.c_str());
	
	if(!file.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (false);
	}

	std::string		line;
	// skip headerline ("date" | "value")
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string	dateStr;
		std::string	valueStr;

		//	splitLine already trimmed both fragments
		if(!splitLine(line, dateStr, valueStr))
			continue ;

		#ifdef DEBUG
		std::cout << "[PARSEINPUT]\t"<< "date: [" << dateStr << "] value: [" << valueStr << "]" << std::endl;
		#endif

		if (!validateDate(dateStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;

		}
		if (!validateValue(valueStr))
			continue ;

		try
		{
			double	rate = getRate(dateStr);
			double	value = std::strtod(valueStr.c_str(), NULL);

			std::cout << dateStr << " => " << valueStr << " = " << value * rate << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << "Error: no earlier date available for date " << dateStr << std::endl;
		}
	}
	return (true);
}
