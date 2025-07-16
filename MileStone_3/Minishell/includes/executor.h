/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:02:54 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/10 15:33:18 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "msh.h"

// check_redirections
// int				check_outfile(t_lexer *redirections);
// int				check_infile(t_lexer *redirections);
// int				handle_redirections(t_simple_cmds *cmd, t_tools *tools);
int				check_redirections(t_simple_cmds *cmd);

// executor
int				executor(t_tools *tools);
t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd);
int				pipe_wait(int *pid, int amount);

// handle_cmd
int				find_cmd(t_simple_cmds *cmd, t_tools *tools);
void			handle_cmd(t_simple_cmds *cmd, t_tools *tools);
void			dup_cmd(t_simple_cmds *cmd, t_tools *tools,
					int end[2], int fd_in);
void			single_cmd(t_simple_cmds *cmd, t_tools *tools);

// heredoc
int				send_heredoc(t_tools *tools, t_simple_cmds *cmd);

#endif