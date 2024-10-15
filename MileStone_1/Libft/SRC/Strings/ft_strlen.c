/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:01:36 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:40:13 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strlen function calculates the length of a given string.*/
#include "../../libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
