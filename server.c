/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:49:10 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/23 13:21:45 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include "minitalk.h"

static t_char cur_char;

void	catch_client(int sig_num)
{
	char mask = 1 << cur_char.cur_bit;
	if (cur_char.cur_bit == 7)
	{
		write(1, &cur_char.c, 1);
		if (!cur_char.c)
			write(1,"\n", 1);
		cur_char.c = 0;
		cur_char.cur_bit = 0;	
		return ;
	}
	if (sig_num == SIGUSR1)
		cur_char.c = ((cur_char.c & ~mask) | (1 << cur_char.cur_bit));
	else
		cur_char.c = ((cur_char.c & ~mask) | (0 << cur_char.cur_bit));
	cur_char.cur_bit++;
}

int	main(void)
{
	int			server_pid;
	struct		sigaction sact;
	sigset_t	mask;
	
	server_pid = getpid();
	printf("Server pid is:%d\n", server_pid);
	cur_char.c = 0;
	cur_char.cur_bit = 0;	
	sigemptyset(&mask);
  	sact.sa_handler = &catch_client;
	sact.sa_flags = SA_RESTART;
	sact.sa_mask = mask; 
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
		pause();
	return (0);
}
