/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:40 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 20:17:49 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	j;

	j = (long long)n;
	if (j < 0)
	{
		ft_putchar_fd('-', fd);
		j *= -1;
	}
	if (j < 10)
		ft_putchar_fd(j + '0', fd);
	if (j >= 10)
	{
		ft_putnbr_fd(j / 10, fd);
		ft_putchar_fd((j % 10) + '0', fd);
	}
}
