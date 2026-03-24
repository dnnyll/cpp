
#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
	private:

	std::string const	_name;
	int					_grade;

	public:

	//	OCF
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	//	accessors
	const	std::string& getName() const;
	int		getGrade() const;

	//	actions
	void	incrementGrade();
	void	decrementGrade();

	// exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};	
};

//	operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif