/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:40 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 20:19:34 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_determine_unsigned_nbr_size(unsigned int nbr)
{
	int			i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_determine_nbr_size(long long nbr)
{
	int			i;
	int			neg_or_pos;

	neg_or_pos = 0;
	i = 0;
	if (nbr == 0)
		i++;
	if (nbr < 0)
	{
		neg_or_pos = 1;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	if (neg_or_pos)
		i++;
	return (i);
}

int	ft_if_num(char c, va_list ap)
{
	long long	nbr;

	if (c == 'i' || c == 'd')
	{
		nbr = va_arg(ap, int);
		ft_putnbr_fd(nbr, 1);
		return (ft_determine_nbr_size(nbr));
	}
	if (c == 'u')
	{
		nbr = va_arg(ap, unsigned int);
		ft_putunsignedint_fd(nbr, 1);
		return (ft_determine_unsigned_nbr_size(nbr));
	}
	return (0);
}
