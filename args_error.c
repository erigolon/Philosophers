/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:40:45 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 16:32:52 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	is_number(char **str)
{
	int	i;
	int	o;

	i = 1;
	while (str[i])
	{
		o = 0;
		while (str[i][o])
		{
			if (!(str[i][o] >= '0' && str[i][o] <= '9') && str[i][o] != '+'
				&& str[i][o] != '-')
				return (1);
			o++;
		}
		i++;
	}
	return (0);
}

int	check_signal(char **str, int i)
{
	int	o;
	int	signal;

	while (str[i])
	{
		if ((str[i][0] == '-' || str[i][0] == '+') && str[i][1] == '\0')
			return (1);
		i++;
	}
	i = 1;
	while (str[i])
	{
		o = 0;
		signal = 0;
		while (str[i][o])
		{
			if (str[i][o] == '+' || str[i][o] == '-')
				signal += 1;
			if (signal >= 2)
				return (1);
			o++;
		}
		i++;
	}
	return (0);
}

int	more_signal_check(char **str)
{
	int	i;
	int	o;

	i = 0;
	while (str[i])
	{
		o = 0;
		if (str[i][o] == '+' || str[i][o] == '-')
			o++;
		while (str[i][o])
		{
			if (str[i][o] == '+' || str[i][o] == '-')
				return (1);
			o++;
		}
		i++;
	}
	return (0);
}

int	check_max_min(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf(ARGS_MSG), 1);
	if (is_number(argv))
		return (printf(ARGS_MSG_2), 1);
	if (check_signal(argv, 1))
		return (printf(ARGS_MSG_2), 1);
	if (more_signal_check(argv))
		return (printf(ARGS_MSG_2), 1);
	if (check_max_min(argv))
		return (printf(ARGS_MSG_2), 1);
	return (0);
}
