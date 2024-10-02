/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:44:01 by yurolive          #+#    #+#             */
/*   Updated: 2024/09/23 15:19:05 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
//#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	// int	real_len;
	// int	custom_len;

	// printf("Real printf test:\n");
	// real_len = printf("printf1 output: \" %p %p \"\n", (void *)0, (void *)0);
	// printf("Length returned by real printf: %d\n\n", real_len);

	// printf("ft_printf test:\n");
	// custom_len = ft_printf("printf2 output: \" %p %p \"\n", (void *)0, (void *)0);
	// printf("Length returned by ft_printf: %d\n", custom_len);

	// if (real_len == custom_len)
	// 	printf("\nTest passed: Lengths match!\n");
	// else
	// 	printf("\nTest failed: Lengths do not match!\n");

	// return (0);
	ft_putnbr_fd(ft_isalpha('A'), 1);
	ft_putnbr_fd(ft_isalpha('1'), 1);
}
