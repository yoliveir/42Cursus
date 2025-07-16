/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:42:32 by yurolive          #+#    #+#             */
/*   Updated: 2025/05/15 11:14:17 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int	minishell_loop(t_tools *tools);

int	implement_tools(t_tools *tools)
{
	tools->simple_cmds = NULL;
	tools->lexer_list = NULL;
	tools->reset = false;
	tools->pid = NULL;
	tools->heredoc = false;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
	parse_envp(tools);
	init_signals();
	return (1);
}

int	reset_tools(t_tools *tools)
{
	ft_simple_cmdsclear(&tools->simple_cmds);
	free(tools->args);
	if (tools->pid)
		free(tools->pid);
	free_arr(tools->paths);
	implement_tools(tools);
	tools->reset = true;
	minishell_loop(tools);
	return (1);
}

int	prepare_executor(t_tools *tools)
{
	signal(SIGQUIT, sigquit_handler);
	g_global.in_cmd = 1;
	if (tools->pipes == 0)
		single_cmd(tools->simple_cmds, tools);
	else
	{
		tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);
		if (!tools->pid)
			return (ft_error(1, tools));
		executor(tools);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}

int	minishell_loop(t_tools *tools)
{
	char	*tmp;

	tools->args = readline(READLINE_MSG);
	if (!tools->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	tmp = ft_strtrim(tools->args, " ");
	free(tools->args);
	if (!tmp)
		return (reset_tools(tools));
	tools->args = tmp;
	if (tools->args[0] == '\0')
		return (reset_tools(tools));
	add_history(tools->args);
	if (!count_quotes(tools->args))
		return (ft_error(2, tools));
	if (!token_reader(tools))
		return (ft_error(1, tools));
	parser(tools);
	prepare_executor(tools);
	reset_tools(tools);
	return (1);
}
