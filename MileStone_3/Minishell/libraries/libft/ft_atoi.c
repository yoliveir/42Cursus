/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:06:35 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 20:06:39 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	p_n;
	int	i;

	i = 0;
	ret = 0;
	p_n = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			p_n *= -1;
		str++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
		if (i == 10 && str[i] && p_n == -1)
			return (0);
		else if (i == 10 && str[i])
			return (-1);
	}
	return (ret * p_n);
}
