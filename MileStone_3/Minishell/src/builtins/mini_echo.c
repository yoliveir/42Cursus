/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:17:04 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 19:08:41 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_lines(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}

int	mini_echo(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int		i;
	int		j;
	bool	n_option;

	i = 1;
	n_option = false;
	(void) tools;
	while (simple_cmd->str[i] && simple_cmd->str[i][0] == '-'
		&& simple_cmd->str[i][1] == 'n')
	{
		j = 1;
		while (simple_cmd->str[i][j] == 'n')
			j++;
		if (simple_cmd->str[i][j] == '\0')
			n_option = true;
		else
			break ;
		i++;
	}
	print_lines(i, simple_cmd->str, STDOUT_FILENO);
	if (n_option == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
