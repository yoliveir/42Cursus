/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:43:04 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 19:09:14 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	mini_env(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int		i;

	(void) simple_cmd;
	i = 0;
	while (tools->envp[i])
	{
		ft_putendl_fd(tools->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
