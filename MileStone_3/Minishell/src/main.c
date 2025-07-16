/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:45:43 by yurolive          #+#    #+#             */
/*   Updated: 2025/05/15 11:22:14 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	tools.envp = ft_arrdup(envp);
	find_pwd(&tools);
	implement_tools(&tools);
	using_history();
	read_history(".42sh_history");
	printf("\n%s\n\n", WELCOME_MSG);
	minishell_loop(&tools);
	read_history(".42sh_history");
	return (0);
}
