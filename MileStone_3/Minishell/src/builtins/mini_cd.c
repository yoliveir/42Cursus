/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:17:04 by yurolive          #+#    #+#             */
/*   Updated: 2025/05/15 11:17:40 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

#define HOME_KEY "HOME="
#define OLDPWD_KEY "OLDPWD="

char	*find_path_ret(char *str, t_tools *tools)
{
	int		i;
	size_t	key_len;

	if (!str || !tools || !tools->envp)
		return (NULL);
	key_len = ft_strlen(str);
	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], str, key_len))
			return (ft_substr(tools->envp[i], key_len,
					ft_strlen(tools->envp[i]) - key_len));
		i++;
	}
	return (NULL);
}

int	specific_path(t_tools *tools, char *str)
{
	char	*tmp;
	int		ret;
	char	*key;

	tmp = find_path_ret(str, tools);
	if (!tmp)
		return (1);
	ret = chdir(tmp);
	free(tmp);
	if (ret != 0)
	{
		key = ft_substr(str, 0, ft_strlen(str) - 1);
		if (key)
		{
			ft_putstr_fd(key, STDERR_FILENO);
			free(key);
		}
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

void	change_path(t_tools *tools)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!tmp)
	{
		perror("getcwd");
		return ;
	}
	if (tools->old_pwd)
		free(tools->old_pwd);
	tools->old_pwd = tools->pwd;
	tools->pwd = ft_strdup(tmp);
	free(tmp);
	if (!tools->pwd)
		perror("ft_strdup");
}

void	add_path_to_env(t_tools *tools)
{
	int		i;
	char	*tmp;

	if (!tools || !tools->envp)
		return ;
	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], "PWD=", 4) && tools->pwd)
		{
			tmp = ft_strjoin("PWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		else if (!ft_strncmp(tools->envp[i], "OLDPWD=", 7) && tools->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", tools->old_pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		i++;
	}
}

int	mini_cd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int	ret;

	if (!simple_cmd || !simple_cmd->str)
		return (EXIT_FAILURE);
	if (!simple_cmd->str[1])
		ret = specific_path(tools, HOME_KEY);
	else if (!ft_strncmp(simple_cmd->str[1], "-", 2))
		ret = specific_path(tools, OLDPWD_KEY);
	else
	{
		ret = chdir(simple_cmd->str[1]);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(tools);
	add_path_to_env(tools);
	return (EXIT_SUCCESS);
}
