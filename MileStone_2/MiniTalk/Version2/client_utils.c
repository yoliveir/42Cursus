#include "minitalk.h"

int ft_atoi(const char *str)
{
    int i = 0;
    long long int nbr = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + str[i] - '0';
        i++;
        if (nbr > INT_MAX)
            return (-1);
    }
    return (nbr);
}

void ft_putchar(int c)
{
    write(1, &c, 1);
}

void ft_putnbr(int num)
{
    if (num > 9)
    {
        ft_putnbr(num / 10);
        num = num % 10;
    }
    if (num <= 9)
        ft_putchar(('0' + num));
}