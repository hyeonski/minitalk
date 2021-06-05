/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonski <hyeonski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:29:12 by hyeonski          #+#    #+#             */
/*   Updated: 2021/06/05 20:02:48 by hyeonski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int g_flag;

void signal_handle(int signo)
{
	if (signo == SIGUSR1)
		g_flag = 1;
	else if (signo == SIGUSR2)
		g_flag = 0;
	else
		g_flag = -1;
}

int is_bit_set(int idx, char buf)
{
	char mask = 1 << (7 - idx);
	return ((buf & mask) != 0);
}

void send_msg(pid_t pid, char *str)
{
	char buf;
	int i;
	int j;
	int flag;

	pause();
	i = 0;
	while (str[i])
	{
		buf = str[i];
		j = 0;
		while (j < 8)
		{
			flag = is_bit_set(j, buf);
			usleep(100);
			kill(pid, flag ? SIGUSR1 : SIGUSR2);
			pause();
			if (g_flag != flag || g_flag == -1)
			{
				ft_putendl_fd("fatal error!", STDOUT_FILENO);
				printf("g_flag: %d\n", g_flag);
				exit(1);
			}
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR2);
		pause();
		if (g_flag != 0)
		{
			ft_putendl_fd("fatal error!", STDOUT_FILENO);
			printf("g_flag: %d\n", g_flag);
			exit(1);
		}
		j++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_putstr_fd("client pid:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	signal(SIGUSR1, signal_handle);
	signal(SIGUSR2, signal_handle);
	send_msg(ft_atoi(argv[1]), argv[2]);
}