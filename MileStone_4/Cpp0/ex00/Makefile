# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:38:29 by yurolive          #+#    #+#              #
#    Updated: 2025/06/18 16:46:06 by yurolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Las Flags para compilar
FLAGS = -Wall -Wextra -Werror -std=c++98

# Definicion de Colores
RESET      = \033[0m
RED        = \033[31m 
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
CYAN       = \033[36m
MAGENTA    = \033[35m

# El nombre del "Programa"
NAME = megaphone

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building ${NAME}...${RESET}"
	@c++ $(FLAGS) -o $(NAME) $(OBJ)
	@echo "${GREEN}${NAME} created${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re