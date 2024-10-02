# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 10:10:38 by yurolive          #+#    #+#              #
#    Updated: 2024/09/24 10:10:40 by yurolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Las Flags para compilar
FLAG = -Wall -Wextra -Werror
# El nombre del "Programa"
NAME = libftprintf.a
# Los Archivos fuente .c
SRC	=	ft_printf_utils.c \
			ft_printf.c \
			ft_put_hex.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putptr_hex.c \
			ft_putstr.c \
			ft_put_un_nbr.c \
# Los Archivos "librerias" .o
OBJ = ${SRC:.c=.o}
# Se refiere a lo ejecutable
all: ${NAME}
# Creo el "Programa" a partir de los archivos .o
${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@echo "${NAME} created and indexed"
# Creo los archivos .o
%.o:%.c
	@gcc ${FLAG} -c $< -o $@
# Borra los archivos .o
clean:
	@rm -f ${OBJ}
	@echo "OBJ cleaned"
# Borra los archivos .o y el "Programa"
fclean:	clean
	@rm -f ${OBJ}
	@rm -f ${NAME}
	@echo "All objects and executable cleaned"
# Borra el "Programa" y recompila
re: fclean all
# Indica a Make que no son archivos reales, sino nombres de objetivos, Esto evita conflictos si existieran archivos con esos mismos nombres.
.PHONY: all clean fclean re
