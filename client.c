/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:49:12 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/24 13:40:33 by tguimara         ###   ########.fr       */
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
			g_char.get_response = 0;
			if (*mensage & 0x01)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			current_bit++;
			*mensage = *mensage >> 1;
			while (g_char.get_response == 0)
				;
		}
		mensage++;
	}
	return (1);
}

void	server_response(int sig_num)
{
	if (sig_num == SIGUSR1)
		write(1, "1", 1);
	g_char.get_response = 1;
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
	server_pid = ft_atoi(*(argv + 1));
	signal(SIGUSR1, server_response);
	if (send_message(server_pid, *(argv + 2)) == 1)
		exit(1);
	else
		exit(-1);
	return (0);
}
