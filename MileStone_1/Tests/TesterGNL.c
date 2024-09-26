/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TesterGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:37 by yurolive          #+#    #+#             */
/*   Updated: 2024/09/26 12:59:18 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    // Abre un archivo para leer (cambia "archivo.txt" por el nombre de tu archivo)
    fd = open("TextoGNL.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
	
	line = get_next_line(fd);
        printf("%s", line);
        free(line);
		
	line = get_next_line(fd);
        printf("%s", line);
        free(line);
		
	// line = get_next_line(fd);
    //     printf("%s", line);
    //     free(line);

    //Lee el archivo línea por línea
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     // Imprime la línea leída
    //     printf("%s", line);
    //     // Libera la memoria de la línea
    //     free(line);
    // }

    // Cierra el archivo
    close(fd);
    return (0);
}