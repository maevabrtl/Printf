#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

#endif