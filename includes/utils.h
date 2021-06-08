/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonski <hyeonski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:43:53 by hyeonseun         #+#    #+#             */
/*   Updated: 2021/06/05 21:32:58 by hyeonski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4095

# endif

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
int					ft_strlen(const char *s);
char				*ft_strchr(char *str, int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *str, unsigned int start, int len);
char				*ft_strdup(char *str);
int					get_next_line(int fd, char **line);

#endif
