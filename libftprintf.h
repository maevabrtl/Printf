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
void	putstr(char *str);
char	*ft_itoa_base(int n, int base);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		count_args(char *str);
t_list	*maketolist(char *str, t_list *lst);
void	ft_printf(char	*str, ...);
t_list	*ft_cut(char *str);
void	handle_percent(t_list *lst, int nbargs, va_list args);

#endif