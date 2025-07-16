/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:17:26 by yurolive          #+#    #+#             */
/*   Updated: 2025/05/15 11:07:26 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "parser.h"
# include "utils.h"
# include "error.h"
# include "lexer.h"
# include "color.h"
# include "builtins.h"
# include "executor.h"

int		parse_envp(t_tools *tools);
int		find_pwd(t_tools *tools);
int		reset_tools(t_tools *tools);
char	**expander(t_tools *tools, char **str);
char	*expander_str(t_tools *tools, char *str);
size_t	dollar_sign(char *str);
char	*char_to_str(char c);
int		after_dol_lenght(char *str, int j);
void	free_things(char *tmp2, t_tools *tools, int i);
void	print_parser(t_simple_cmds simple_cmds);
char	*delete_quotes_value(char *str);
void	sigint_handler(int sig);
void	sigquit_handler(int sig);
void	init_signals(void);
char	*delete_quotes(char *str, char c);
char	*delete_quotes_export(char *str, char c);
int		question_mark(char **tmp);

//builtins
int		(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

extern t_global	g_global;

#endif