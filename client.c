/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:49:12 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/23 16:31:52 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_message(int server_pid, char *mensage)
{
	int	current_bit;

	while (*mensage)
	{
		current_bit = 0;
		while (current_bit < 8)
		{
			if (*mensage & 0x01)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			current_bit++;
			usleep(600);
			*mensage = *mensage >> 1;
		}
		mensage++;
	}
	return (1);
}

void	server_response(int sig_num)
{
	if (sig_num == SIGUSR1)
		ft_printf("signal received by the server\n");
}

int	main(int argc, char **argv)
{
	int			server_pid;

	if (argc != 3)
	{
		ft_printf("Sorry, client should be executed in the following format:\n");
		ft_printf("{client [server_pid] [message]?}\n");
		return (-1);
	}
	server_pid = atoi(*(argv + 1));
	signal(SIGUSR1, server_response);
	send_message(server_pid, *(argv + 2));
	return (0);
}
