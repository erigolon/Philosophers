/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:37:34 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 12:32:02 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_of_philo)
	{
		table->philo[i].table = table;
		table->philo[i].id = i + 1;
		table->philo[i].meals_count = 0;
		table->philo[i].eating = 0;
		table->philo[i].time_to_die = table->death_time;
		pthread_mutex_init(&table->philo[i].lock, NULL);
		i++;
	}
}

void	init_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i <= table->n_of_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	i = 1;
	table->philo[0].l_fork = &table->forks[0];
	table->philo[0].r_fork = &table->forks[table->n_of_philo - 1];
	while (i < table->n_of_philo)
	{
		table->philo[i].l_fork = &table->forks[i];
		table->philo[i].r_fork = &table->forks[i - 1];
		i++;
	}
}

int	init_mallocs(t_table *table)
{
	table->th_id = malloc(sizeof(pthread_t) * table->n_of_philo);
	if (!table->th_id)
		return (1);
	table->philo = malloc(sizeof(t_philo) * table->n_of_philo);
	if (!table->philo)
		return (1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_of_philo);
	if (!table->forks)
		return (1);
	return (0);
}

void	init_table(t_table *table, int argc, char **argv)
{
	table->n_of_philo = (int)ft_atoi(argv[1]);
	table->death_time = (u_int64_t)ft_atoi(argv[2]);
	table->eat_time = (u_int64_t)ft_atoi(argv[3]);
	table->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	if (argc == 6)
		table->n_of_meals = (int)ft_atoi(argv[5]);
	else
		table->n_of_meals = -1;
	table->death = 0;
	table->end_meals = 0;
	pthread_mutex_init(&table->lock, NULL);
	pthread_mutex_init(&table->write, NULL);
}

int	init(t_table *table, int argc, char **argv)
{
	init_table(table, argc, argv);
	if (init_mallocs(table))
		return (1);
	init_fork(table);
	init_philos(table);
	return (0);
}
