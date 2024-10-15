/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:32:24 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/14 17:11:45 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>

int	ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;

	nbr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr > INT_MAX)
			return (-1);
	}
	return (nbr);
}

void	conv_bin(char *s, int pidserv)
{
	int		i;
	int		base;
	char	letra;

	i = 0;
	while (s[i])
	{
		base = 128;
		letra = s[i];
		while (base > 0)
		{
			if (letra >= base)
			{
				kill(pidserv, SIGUSR1);
				letra = letra - base;
			}
			else
				kill(pidserv, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pidserv;

	if (argc != 3)
		return (-1);
	pidserv = ft_atoi(argv[1]);
	conv_bin(argv[2], pidserv);
	return (0);
}
