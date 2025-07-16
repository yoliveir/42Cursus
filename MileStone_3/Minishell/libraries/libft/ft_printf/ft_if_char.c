/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:40 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 20:19:28 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_if_char(char c, va_list ap)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	if (c == 's')
		return (ft_putstr_size(va_arg(ap, char *), 1));
	return (0);
}
