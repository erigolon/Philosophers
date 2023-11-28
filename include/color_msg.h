/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:07:26 by erigolon          #+#    #+#             */
/*   Updated: 2023/11/08 15:49:59 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_MSG_H
# define COLOR_MSG_H

/*			COLORS				*/

# define DEFAULT    	"\033[0m"
# define CYAN_BOLD		"\033[1;36m"
# define BLUE_BOLD		"\033[1;34m"
# define RED_BOLD		"\033[1;31m"
# define GREEN_BOLD		"\033[1;32m"
# define YELLOW_BOLD	"\033[1;33m"

/*			MESSAGES			*/

//	Arguments errors
# define ARGS_MSG		"\033[1;31mWrong number of arguments :(\033[0m\n"
# define ARGS_MSG_2		"\033[1;31mError in the arguments :(\033[0m\n"

//	Timestamp messages
# define FORK_MSG		"\033[1;33mhas taken a fork\033[0m"
# define EAT_MSG		"\033[1;32mis eating\033[0m"
# define SLEEP_MSG		"\033[1;34mis sleeping\033[0m"
# define THINK_MSG		"\033[1;36mis thinking\033[0m"
# define DIE_MSG		"\033[1;31mdied\033[0m"

#endif