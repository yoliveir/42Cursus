/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestPrintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:30:50 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/02 15:19:47 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = "Hola!";
	char	c = 'C';
	int	i, j;

	i = ft_printf("My Printf: ----\nChar %%c: %c\nString %%s: %s\nPointers %%p: %p\nDigit %%d: %d\nInteger %%i: %i\nUnsigned int %%u: %u\nHexadecimal lower %%x: %x\nHexadecimal upper %%X: %X\nPorcentage %%: %%", c, str, str, 42, 4242, 1234567891, 42,  42);
	printf("\nMy Len: %d\n\n", i);
	j = printf("Of Printf: ----\nChar %%c: %c\nString %%s: %s\nPointers %%p: %p\nDigit %%d: %d\nInteger %%i: %i\nUnsigned int %%u: %u\nHexadecimal lower %%x: %x\nHexadecimal upper %%X: %X\nPorcentage %%: %%", c, str, str, 42, 4242, 1234567891, 42,  42);
	printf("\nOf Len: %d", j);
}
