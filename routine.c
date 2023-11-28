/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:34:41 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 16:16:24 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	messages(philo, FORK_MSG);
	pthread_mutex_lock(philo->l_fork);
	messages(philo, FORK_MSG);
}

void	drop_n_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	messages(philo, SLEEP_MSG);
	ft_usleep(philo->table->sleep_time, philo);
}

void	eat(t_philo *philo)
{
	pick_fork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->table->death_time;
	messages(philo, EAT_MSG);
	philo->meals_count++;
	ft_usleep(philo->table->eat_time, philo);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_n_sleep(philo);
}

void	messages(t_philo *philo, char *message)
{
	u_int64_t	actual_time;

	pthread_mutex_lock(&philo->table->write);
	actual_time = get_time() - philo->table->start_time;
	if (ft_strcmp(DIE_MSG, message) == 0 && philo->table->death == 0)
	{
		printf("%llu %d %s\n", actual_time, philo->id, message);
		philo->table->death = 1;
	}
	if (!philo->table->death)
		printf("%llu %d %s\n", actual_time, philo->id, message);
	pthread_mutex_unlock(&philo->table->write);
}
