/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:43:02 by yurolive          #+#    #+#             */
/*   Updated: 2025/04/08 17:39:18 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = (gettime(MILISECOND) - philo->data->start_simulation);
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->philo_mutex, LOCK);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !simulation_finished(philo->data))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !simulation_finished(philo->data))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->data))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(philo->data))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%-6ld %d died\n", elapsed, philo->id);
	safe_mutex_handle(&philo->philo_mutex, UNLOCK);
}
