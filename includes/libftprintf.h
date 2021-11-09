#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		check_error(char *str);
void	ft_printf(char	*str, ...);
int		find_percent_index(char *str, int si);
int		count_args(char *str);
t_list	*maketolist(char *str, t_list *lst);
t_list	*ft_cut(char *str);
t_list	*ft_parse(char *str, int *ct, t_list *lst);
void	handle_percent(t_list *lst, va_list args);
void	u_percent(t_list *lst, va_list args, char *ret);
void	i_percent(t_list *lst, va_list args, char *ret);
void    error_exit(int n);
void	puterror(char *str);

#endif