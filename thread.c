/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:32:44 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:38 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	*waiter(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (philo->table->death == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->table->end_meals >= philo->table->n_of_philo)
			philo->table->death = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

void	*status(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (philo->table->death == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(philo, DIE_MSG);
		if (philo->meals_count == philo->table->n_of_meals)
		{
			pthread_mutex_lock(&philo->table->lock);
			philo->meals_count++;
			philo->table->end_meals++;
			pthread_mutex_unlock(&philo->table->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	philo->time_to_die = get_time() + philo->table->death_time;
	if (pthread_create(&philo->th, NULL, &status, philo_pointer))
		return ((void *)1);
	while (philo->table->death == 0)
	{
		eat(philo);
		messages(philo, THINK_MSG);
	}
	if (pthread_join(philo->th, NULL))
		return ((void *)1);
	return (NULL);
}

int	init_thread(t_table *table)
{
	int			i;
	pthread_t	th_waiter;

	i = 0;
	table->start_time = get_time();
	if (table->n_of_meals > 0)
	{
		if (pthread_create(&th_waiter, NULL, &waiter, &table->philo[0]))
			return (1);
	}
	while (i < table->n_of_philo)
	{
		if (pthread_create(&table->th_id[i], NULL, &routine, &table->philo[i]))
			return (1);
		ft_usleep_2(1);
		i++;
	}
	i = 0;
	while (i < table->n_of_philo)
	{
		if (pthread_join(table->th_id[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
