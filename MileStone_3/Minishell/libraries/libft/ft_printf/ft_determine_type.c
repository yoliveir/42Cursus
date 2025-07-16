/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:40 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 20:19:24 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_determine_type(char c, va_list ap)
{
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (c == 'c' || c == 's')
		return (ft_if_char(c, ap));
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_if_num(c, ap));
	if (c == 'x' || c == 'X' || c == 'p')
		return (ft_if_hex(c, ap));
	return (0);
}
