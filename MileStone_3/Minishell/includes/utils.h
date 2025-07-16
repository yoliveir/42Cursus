/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:33:43 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/10 15:30:33 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "msh.h"

// utils
int				count_quotes(char *line);
int				implement_tools(t_tools *tools);
char			**ft_arrdup(char **arr);

int				minishell_loop(t_tools *tools);

//t_simple_cmds_utils
t_simple_cmds	*ft_simple_cmdsnew(char **str,
					int num_redirections, t_lexer *redirections);
void			ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);
void			ft_simple_cmds_rm_first(t_simple_cmds **lst);
void			ft_simple_cmdsclear(t_simple_cmds **lst);
t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);

//t_lexer_utils
t_lexer			*ft_lexernew(char *str, int token);
void			ft_lexeradd_back(t_lexer **lst, t_lexer *new);
void			ft_lexerdelone(t_lexer **lst, int i);
void			ft_lexerclear(t_lexer **lst);

//
int				token_reader(t_tools *tools);
int				add_node(char *str, t_tokens token, t_lexer **lexer_list);
t_tokens		check_token(int c);
int				handle_token(char *str, int i, t_lexer **lexer_list);

#endif