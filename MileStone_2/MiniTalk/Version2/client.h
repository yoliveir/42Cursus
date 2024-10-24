#ifndef CLIENT_H
#define CLIENT_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>

int ft_atoi(const char *str);
void conv_bin(char *s, int pidserv);
void ft_putchar(int c);
void ft_putnbr(int num);

#endif // CLIENT_H