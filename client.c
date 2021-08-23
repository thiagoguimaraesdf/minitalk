/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:49:12 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/23 14:24:04 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <signal.h>
#include "minitalk.h"

int	send_message(int server_pid, char *mensage)
{
	int current_bit;
	
	while(*mensage)
	{
		current_bit = 0;
		while(current_bit < 8)
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
		printf("signal received by the server");
}

int	main(int argc, char **argv)
{
	int			server_pid;
	struct		sigaction sact;
	
	if (argc != 3)
	{
		printf("Sorry, client should be executed in the following format:\n");
		printf("{client [server_pid] [message]?}\n");
		return (-1);
	}
	server_pid = atoi(*(argv + 1));
	printf("sever_pid:%d\n", server_pid);
  	sact.sa_handler = &server_response;
	sact.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sact, NULL);
	return (0);
}