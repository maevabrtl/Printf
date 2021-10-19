#ifndef LIBFTPRINTF_H
# define LIBFPRINTF_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct 		s_list
{
	char			*content;
	int				size;
	struct s_list	*next;
}					t_list;


t_list	*ft_lstnew(char *content);
char	*ft_strchr(char *s, char c);
void	ft_strncpy(char *dst, const char *src, int n);
t_list	*f1(char *str);

#endif