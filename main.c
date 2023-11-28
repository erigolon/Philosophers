/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:26:16 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 16:36:31 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

/*
static void	ft_leaks(void)
{
	system("leaks -q philo");
}
atexit(ft_leaks);
*/

void	one_philo(t_table *table)
{
	printf("%d %d %s\n", 0, 1, FORK_MSG);
	ft_usleep_2(table->death_time);
	printf("%llu %d %s\n", table->death_time, 1, DIE_MSG);
}

void	free_and_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_of_philo)
	{
		pthread_mutex_destroy(&table->philo[i].lock);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->lock);
	pthread_mutex_destroy(&table->write);
	free(table->th_id);
	free(table->philo);
	free(table->forks);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_args(argc, argv))
		return (1);
	if (init(&table, argc, argv))
		return (1);
	if (table.n_of_philo == 1)
	{
		one_philo(&table);
		free_and_destroy(&table);
		return (0);
	}
	if (init_thread(&table))
		return (1);
	free_and_destroy(&table);
	return (0);
}
