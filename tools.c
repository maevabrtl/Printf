#include "libftprintf.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->next = 0;
	new->content = content;
	return (new);
}

char	*ft_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (s[0] == 'c')
		return (s + 2);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strncpy(char *dst, const char *src, int n)
{
	int i;
	dst[n + 1] = '\0';
	while (n >= 0)
	{
		dst[n] = src[n];
		n--;
	}
}

void	putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, &(*str), 1);
		str++;
	}
}






void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		*str = 0;
		i++;
		str++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (ret = NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

// working
int	count_args(char *str)
{
	int nbargs;
	int ct;

	nbargs = 0;
	ct = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			nbargs++;
		*str++;
	}
	return (nbargs);
}


//need to find how to put type shit in 25 lines
t_list *get_the_args(int nbargs, ...)
{
	t_list *arglist;
	va_list args;

	t_list *arglist = malloc(sizeof(t_list *));
	if (arglist == NULL)
		return (NULL);
	va_start(args, nbargs);
	while (nbargs > 0)
	{
		arglist->content = va_arg(args, 'type');
		nbargs--;
	}
	va_end(args);
	return (arglist)
}