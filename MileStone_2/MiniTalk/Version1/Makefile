# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:55:41 by yurolive          #+#    #+#              #
#    Updated: 2024/10/15 15:15:19 by yurolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Las Flags para compilar
FLAG = -Wall -Wextra -Werror

# Definicion de Colores
RESET      = \033[0m
RED        = \033[31m 
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
CYAN       = \033[36m
MAGENTA    = \033[35m

# Los nombres de los "Programas"
SRV = server
CLN = client

# Los Archivos .c
SRV_SRC = server.c
CLN_SRC = client.c 

# Archivos .o
SRV_OBJ = ${SRV_SRC:.c=.o}
CLN_OBJ = ${CLN_SRC:.c=.o}

# Se refiere a lo ejecutable
all: check_header ${SRV} ${CLN}

# Verificar si se debe mostrar el encabezado
check_header:
	@if [ ! -f ${SRV} ] || [ ! -f ${CLN} ]; then \
		echo "${MAGENTA}"; \
		echo "========================================="; \
		echo "          MINITALK - BUILD PROCESS       "; \
		echo "========================================="; \
		echo "${RESET}"; \
	else \
		echo "${RED}=========================================${RESET}"; \
		echo "${RED}   Make: Nothing to be done for 'all'${RESET}"; \
		echo "${RED}=========================================${RESET}"; \
		exit 0; \
	fi

# Creo los "Programas" a partir de los archivos .o
${SRV}: ${SRV_OBJ}
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building ${SRV}...${RESET}"
	@cc ${SRV_OBJ} -o $@
	@echo "${GREEN}${SRV} created${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

${CLN}: ${CLN_OBJ}
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building ${CLN}...${RESET}"
	@cc ${CLN_OBJ} -o $@
	@echo "${GREEN}${CLN} created${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Compilación de archivos .o
%.o: %.c
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Compiling $<...${RESET}"
	@cc ${FLAG} -c $< -o $@
	@echo "${GREEN}Compiled $< into $@${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Borra los archivos .o
clean:
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning object files...${RESET}"
	@rm -f ${CLN_OBJ} ${SRV_OBJ}
	@echo "${GREEN}All object files cleaned.${RESET}"
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""

# Borra los archivos .o y el "Programa"
fclean: clean
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning executables...${RESET}"
	@rm -f ${SRV} ${CLN}
	@echo "${GREEN}Executables cleaned.${RESET}"
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""

# Borra el "Programa" y recompila
re: fclean all

# Indica a Make que no son archivos reales, sino nombres de objetivos, Esto evita conflictos si existieran archivos con esos mismos nombres.
.PHONY: all clean fclean re check_header
