#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
int		ft_strchr(char *s, char c);
void	ft_strncpy(char *dst, const char *src, int n);
void	putstr(char *str);
char	*ft_itoa_base(int n, int base);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void    ft_putchar(char c);
char	*utoa(size_t n, int base, int majbase);
int		check_error(char *str);
int		ft_lstfree(t_list *lst);
int		find_percent_index(char *str, int si);
int		count_args(char *str);
t_list	*maketolist(char *str, t_list *lst);
void	ft_printf(char	*str, ...);
t_list	*ft_cut(char *str);
t_list	*ft_parse(char *str, int *ct, t_list *lst);
void	handle_percent(t_list *lst, va_list args);
void	u_percent(t_list *lst, va_list args, char *ret);
void	i_percent(t_list *lst, va_list args, char *ret);
void    error_exit(int n);
void	puterror(char *str);

#endif