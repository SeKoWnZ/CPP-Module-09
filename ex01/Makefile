# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 18:30:36 by jose-gon          #+#    #+#              #
#    Updated: 2025/10/14 20:29:08 by jose-gon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = ./include

FILES = main.cpp RPN.cpp
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

all : $(NAME)

$(NAME): $(OBJ_FILES)
	c++ $(CFLAGS) -o $@ $^
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	c++ $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
