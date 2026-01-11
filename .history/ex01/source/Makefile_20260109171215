# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 13:39:43 by daniefe2          #+#    #+#              #
#    Updated: 2026/01/09 17:12:16 by daniefe2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# definitions
INC_DIR			=		../include
OBJ_DIR			=		../source/objects
NAME			=		phonebook
CXX				=		c++
CXXFLAGS		=		-Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# sources and objects
SRCS			=		main.cpp \
						phonebook.cpp \
						contact.cpp
					
OBJS			=		$(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# compilation rule
$(OBJ_DIR)/%.o: %.cpp
						mkdir -p $(OBJ_DIR)
						$(CXX) $(CXXFLAGS) -c $< -o $@

# default target
all: $(NAME)

# linking
$(NAME): $(OBJS)
						$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# cleaning
clean:
						rm -rf $(OBJ_DIR)

fclean: clean
						rm -rf $(NAME)

re: fclean all

# phony targets
.PHONY: all clean fclean re
