/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:06:50 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 16:57:25 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_usleep(useconds_t time, t_philo *philo)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
	{
		usleep (time / 1000);
		if (philo->table->death == 1)
			return (0);
	}
	return (0);
}

int	ft_usleep_2(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep (time / 10);
	return (0);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long int	ft_atoi(const char *str)
{
	int				i;
	int				pos_neg;
	long int		result;

	i = 0;
	result = 0;
	pos_neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos_neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10 + (str[i] - 48));
		i++;
	}
	if (pos_neg == -1)
		result = result * -1;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
