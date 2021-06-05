/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonski <hyeonski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:29:12 by hyeonski          #+#    #+#             */
/*   Updated: 2021/06/05 21:35:05 by hyeonski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

t_msg		g_msg;

char		*alloc_char(char c)
{
	char	*p;

	p = (char *)malloc(sizeof(char));
	if (p == NULL)
	{
		ft_putstr_fd("fatal error!\n", STDERR_FILENO);
		exit(1);
	}
	*p = c;
	return (p);
}

void		init_msg(void)
{
	char	*line;

	g_msg.msg = NULL;
	g_msg.buf = 0;
	g_msg.bit_cnt = 0;
	g_msg.client_pid = 0;
	ft_putstr_fd("enter next client pid:\n", STDOUT_FILENO);
	get_next_line(STDIN_FILENO, &line);
	g_msg.client_pid = ft_atoi(line);
	free(line);
	kill(g_msg.client_pid, SIGUSR1);
}

void		print_msg(void)
{
	t_list	*list;

	ft_putstr_fd("received message:[", STDOUT_FILENO);
	list = g_msg.msg;
	while (list != NULL)
	{
		ft_putchar_fd(*(char *)list->content, STDOUT_FILENO);
		list = list->next;
	}
	ft_putstr_fd("]\n", STDOUT_FILENO);
	
}

void		signal_handler(int signo)
{
	g_msg.bit_cnt++;
	g_msg.buf = (g_msg.buf << 1) | (signo == SIGUSR1);
	usleep(50);
	kill(g_msg.client_pid, signo == SIGUSR1 ? SIGUSR1 : SIGUSR2);
	if (g_msg.bit_cnt == 8)
	{
		ft_lstadd_back(&(g_msg.msg), ft_lstnew(alloc_char(g_msg.buf)));
		if (g_msg.buf == '\0')
		{
			print_msg();
			ft_lstclear(&(g_msg.msg), free);
			init_msg();
		}
		g_msg.bit_cnt = 0;
		g_msg.buf = 0;
	}
}

int			main(void)
{
	ft_putstr_fd("server pid:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	init_msg();
	while (1)
	{
		pause();
	}
}