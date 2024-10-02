/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:09:45 by yurolive          #+#    #+#             */
/*   Updated: 2024/09/24 10:09:47 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_hex(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static void	ft_print_hex(unsigned int nb, int isUpper)
{
	if (nb >= 16)
	{
		ft_print_hex((nb / 16), isUpper);
		ft_print_hex(nb % 16, isUpper);
	}
	else if (nb > 9)
	{
		if (isUpper)
			ft_putchar(nb - 10 + 'A');
		else
			ft_putchar(nb - 10 + 'a');
	}
	else
		ft_putchar(nb + '0');
}

int	ft_put_hex(unsigned int nb, char format)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		ft_print_hex(nb, format == 'X');
	return (ft_len_hex(nb));
}
