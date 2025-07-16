/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:45:20 by yurolive          #+#    #+#             */
/*   Updated: 2025/04/21 19:51:07 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		parse_input(&data, av);
		data_init(&data);
		dinner_start(&data);
		clean_data(&data);
	}
	else
		error_exit("Wrong input\nnum_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]");
}
