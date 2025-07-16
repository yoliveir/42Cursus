/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:40 by yurolive          #+#    #+#             */
/*   Updated: 2025/02/21 20:17:25 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	i = len_dst;
	if (len_dst > dstsize)
		return (dstsize + ft_strlen(src));
	while (src[j] && i < (dstsize - 1) && dstsize > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len_dst + ft_strlen(src));
}
