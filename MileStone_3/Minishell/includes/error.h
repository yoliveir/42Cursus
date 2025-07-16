/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:53:39 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/10 15:34:09 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "msh.h"

void	parser_error(int error, t_tools *tools, t_lexer *lexer_list);
int		parser_double_token_error(t_tools *tools, t_lexer *lexer_list,
			t_tokens token);
void	lexer_error(int error, t_tools *tools);
int		cmd_not_found(char *str);
int		export_error(char *c);

//ft_error
int		ft_error(int error, t_tools *tools);

#endif