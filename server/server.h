#ifndef SERVER_HPP
# define SERVER_HPP

# include "libft.h"

typedef struct	s_msg
{
	t_list *msg;
	char buf;
	int bit_cnt;
	pid_t client_pid;
}				t_msg;

#endif