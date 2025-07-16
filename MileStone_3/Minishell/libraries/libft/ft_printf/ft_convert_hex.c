/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:40 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 20:19:21 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_hex(unsigned long n, char *up_or_low)
{
	if (n != 0)
	{
		ft_print_hex(n / 16, up_or_low);
		ft_putchar_fd(up_or_low[n % 16], 1);
	}
}

int	ft_convert_hex(unsigned long n, char *up_or_low)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		ft_putchar_fd(up_or_low[n], 1);
		return (1);
	}
	ft_print_hex(n, up_or_low);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
