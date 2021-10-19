#ifndef LIBFTPRINTF_H
# define LIBFPRINTF_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct 		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;


t_list	*ft_lstnew(char *content);
char	*ft_strchr(char *s, char c);
void	ft_strncpy(char *dst, const char *src, int n);
t_list	*f1(char *str);
void	putstr(char *str);
char		*ft_itoa_base(int n, int base);

#endif