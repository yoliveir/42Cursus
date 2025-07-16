/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:22:55 by yurolive          #+#    #+#             */
/*   Updated: 2025/05/15 11:08:59 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <dirent.h>
# include "msh.h"

//builtins
void	change_path(t_tools *tools);

int		mini_echo(t_tools *tools, t_simple_cmds *simple_cmd);

int		mini_cd(t_tools *tools, t_simple_cmds *simple_cmd);

int		mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd);

int		mini_export(t_tools *tools, t_simple_cmds *simple_cmd);

int		mini_unset(t_tools *tools, t_simple_cmds *simple_cmd);

int		mini_env(t_tools *tools, t_simple_cmds *simple_cmd);

int		mini_exit(t_tools *tools, t_simple_cmds *simple_cmd);

int		mini_continue(t_tools *tools, t_simple_cmds *simple_cmd);

size_t	equal_sign(char *str);
int		check_valid_identifier(char c);

#endif
