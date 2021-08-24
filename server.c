/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:49:10 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/24 13:20:00 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	catch_client_message(int sig_num, siginfo_t *info, void *context)
{
	char	mask;

	(void)context;
	mask = 1 << g_char.cur_bit;
	if (g_char.cur_bit == 7)
	{
		write(1, &g_char.c, 1);
		if (!g_char.c)
			write(1, "\n", 1);
		g_char.c = 0;
		g_char.cur_bit = 0;
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (sig_num == SIGUSR1)
		g_char.c = ((g_char.c & ~mask) | (1 << g_char.cur_bit));
	else
		g_char.c = ((g_char.c & ~mask) | (0 << g_char.cur_bit));
	g_char.cur_bit++;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					server_pid;
	struct sigaction	sact;

	server_pid = getpid();
	ft_printf("Server pid is:%d\n", server_pid);
	g_char.c = 0;
	g_char.cur_bit = 0;
	sact.sa_sigaction = catch_client_message;
	sact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
		pause();
	return (0);
}
