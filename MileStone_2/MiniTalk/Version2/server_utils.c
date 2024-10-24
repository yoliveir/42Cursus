#include "minitalk.h"

ServerState state; // Mantener el estado del servidor

void init_server_state() {
    state.current_client_pid = 0;
    state.bit_index = 0;
    state.message_length = 0;
    state.message_capacity = 1; // Capacidad inicial de 1
    state.message = malloc(state.message_capacity); // Asignar tamaño inicial
    state.message[0] = '\0'; // Asegurarse de que es una cadena válida
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

void conv_txt()
{
    write(1, state.message, state.message_length); // Imprimir la cadena completa
    write(1, "\n", 1); // Nueva línea después del mensaje
}