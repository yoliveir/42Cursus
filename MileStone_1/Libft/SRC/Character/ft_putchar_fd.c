/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:55:55 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:38:58 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*Envía el carácter ’c’ al file descriptor especificado.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
