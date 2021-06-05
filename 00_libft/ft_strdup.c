/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:18:51 by hyeonski          #+#    #+#             */
/*   Updated: 2021/02/06 20:42:54 by hyeonseun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		index;

	index = 0;
	while (src[index])
		index++;
	if (!(dup = malloc(sizeof(char) * (index + 1))))
		return (0);
	index = 0;
	while (src[index] != '\0')
	{
		dup[index] = src[index];
		index++;
	}
	dup[index] = src[index];
	return (dup);
}
