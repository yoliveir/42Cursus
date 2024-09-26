/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:09:39 by yurolive          #+#    #+#             */
/*   Updated: 2024/09/24 10:09:41 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_strlen(char *str);
int	ft_nbr_digits(int nb);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putptr_hex(unsigned long long nb);
int	ft_put_un_nbr(unsigned int nb);
int	ft_put_hex(unsigned int nb, char format);
int	ft_printf(const char *str, ...);

#endif
