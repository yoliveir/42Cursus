# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 16:23:00 by knieve-l          #+#    #+#              #
#    Updated: 2025/02/21 20:21:16 by yurolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
MKDIR = mkdir

CC = gcc

LIBFTP = libraries/libft
PATHB = build/
PATHO = build/objs/
PATHS = src/
PATHSL = src/lexer/
PATHSP = src/parser/
PATHSB = src/builtins/
PATHSEX = src/expander/
PATHSU = src/utils/
PATHSE = src/error/
PATHP = src/pipex/
PATHEX = src/executor/

BUILD_PATHS = $(PATHB) $(PATHO)

src	=	src/main.c \
		src/signals.c \
		src/lexer/handle_quotes.c \
		src/lexer/handle_token.c \
		src/lexer/token_reader.c \
		src/parser/handle_redirections.c \
		src/parser/parser.c \
		src/parser/parser_utils.c \
		src/builtins/builtins.c \
		src/builtins/mini_cd.c \
		src/builtins/mini_echo.c \
		src/builtins/mini_env.c \
		src/builtins/mini_exit.c \
		src/builtins/mini_export.c \
		src/builtins/mini_pwd.c \
		src/builtins/mini_unset.c \
		src/builtins/utils_builtins.c \
		src/utils/minishell_loop.c \
		src/utils/parse_envp.c \
		src/utils/t_lexer_clear_utils.c \
		src/utils/t_lexer_utils.c \
		src/utils/t_simple_cmds_utils.c \
		src/utils/utils.c \
		src/error/error_handling.c \
		src/error/ft_error.c \
		src/executor/check_redirections.c \
		src/executor/executor.c \
		src/executor/handle_cmd.c \
		src/executor/heredoc.c \
		src/executor/executor_utils.c \
		src/expander/expander.c \
		src/expander/expanders_utils.c \
		src/expander/expanders_utils2.c

OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(src))))

FLAGS	=	-Wall -Werror -Wextra -g #-fsanitize=address

LIBFT	=	libraries/libft/libft.a

HEADER	=	includes/builtins.h \
			includes/color.h \
			includes/error.h \
			includes/executor.h \
			includes/lexer.h \
			includes/msh.h \
			includes/parser.h \
			includes/utils.h 

READLINE_DIR = usr/

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
	
INCLUDES =-Iincludes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include 

all: $(BUILD_PATHS) $(NAME)

$(PATHO)%.o:: $(PATHS)%.c
	@echo "Compiling ${notdir $<}			in	$(PATHS)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSL)%.c $(HEADER)
	@echo "Compiling ${notdir $<}			in	$(PATHSL)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSP)%.c $(HEADER)
	@echo "Compiling ${notdir $<}			in	$(PATHSP)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADER)
	@echo "Compiling ${notdir $<}			in	$(PATHSB)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSEX)%.c $(HEADER)
	@echo "Compiling ${notdir $<}			in	$(PATHSEX)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADER)
	@echo "Compiling ${notdir $<}			in	$(PATHSU)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADER)
	@echo "Compiling ${notdir $<}			in	$(PATHSE)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(HEADER)
	@echo "Compiling ${notdir $<}			in	$(PATHEX)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(READLINE_LIB) -o $(NAME)

	@echo "Success"

$(LIBFT):
	@$(MAKE) -s -C libraries/libft

$(PATHB):
	@$(MKDIR) $(PATHB)

$(PATHO):
	@$(MKDIR) $(PATHO)

clean:
	@echo "Cleaning"
	@rm -f $(OBJS)
	@rm -f $(PATHB).tmp*
	@rmdir $(PATHO) $(PATHB)
	@make -s fclean -C libraries/libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: re fclean clean all 