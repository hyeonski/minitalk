/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonski <hyeonski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:41:59 by hyeonski          #+#    #+#             */
/*   Updated: 2021/06/05 21:03:35 by hyeonski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "utils.h"

typedef struct	s_msg
{
	t_list		*msg;
	char		buf;
	int			bit_cnt;
	pid_t		client_pid;
}				t_msg;

#endif