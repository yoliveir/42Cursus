#include "minitalk.h"

void conv_bin(char *s, int pidserv)
{
    int i;
    int base;
    char letra;

    i = 0;
    while (s[i])
    {
        base = 128;
        letra = s[i];
        while (base > 0)
        {
            if (letra >= base)
            {
                kill(pidserv, SIGUSR1);
                letra = letra - base;
            }
            else
                kill(pidserv, SIGUSR2);
            base = base / 2;
            usleep(400);
        }
        i++;
    }
    // Enviar byte nulo al final para indicar el fin del mensaje
    kill(pidserv, SIGUSR1); // Enviar un SIGUSR1 para el byte nulo
}

int main(int argc, char **argv)
{
    int pidserv;

    if (argc != 3)
        return (-1);
    pidserv = ft_atoi(argv[1]);
    conv_bin(argv[2], pidserv);
    return (0);
}
