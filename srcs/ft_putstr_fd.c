/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonski <hyeonski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:17:50 by hyeonski          #+#    #+#             */
/*   Updated: 2021/06/05 21:27:57 by hyeonski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_putstr_fd(char *s, int fd)
{
	int len;

	if (!s || fd < 0)
		return (-1);
	len = ft_strlen(s);
	len = write(fd, s, len);
	return (len);
}
