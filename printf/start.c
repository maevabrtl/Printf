#include "libftprintf.h"

void	ft_printf(char	*str, ...)
{
	t_list *lstfirst;
	int nbargs;

	if (!str)
		return (NULL);
	lstfirst = ft_cut(str);
	nbargs = count_args(str);
	handle_percent(lstfirst, nbargs);
}

t_list	*ft_cut(char *str)
{
	char	*snext;
	char	*stocopy;
	t_list	*lst;
	t_list	*lstfirst;

	snext = str;
	lst = NULL;
	while (*str != '\0')
	{
		snext = ft_strchr(snext, '%');
		stocopy = malloc(sizeof(char) * (snext - str) + 1);
		if (stocopy == NULL)
			return (NULL);
		ft_strncpy(stocopy, str, snext - str);
		if (lst == NULL)
		{
			lst = ft_lstnew(stocopy);
			lstfirst = lst;
		}
		else
			lst = maketolist(stocopy, lst);
		str = snext;
	}
	return (lstfirst);
}

void	handle_percent(t_list *lst, int nbargs)
{
	va_list	args;
	va_start(args, nbargs);
	while (lst != NULL)
	{
		if (lst->content[0] != '%')
			putstr(lst->content);
		else if (lst->content[1] == 's')
		{
			va_arg(args, char *);
			putstr(args);
		}
		else if (lst->content[1] == 'c')
		{
			va_arg(args, char);
			putstr((char *)args);
		}
		else if (lst->content[1] == '%')
			putstr("%%\0");
		else if (lst->content[1] == 'p')
		{
			va_arg(args, void *);
			// ??
		}
		else if (lst->content[1] == 'i')
		{
			va_arg(args, int);
			putstr(ft_itoa_base(args, 10));
		}
		else if (lst->content[1] == 'u' || lst->content[1] == 'x')
		{
			va_args(args, unsigned int);
			if (lst->content[1] == 'x')
				putstr(ft_itoa_base(args, 16));
			else
				putstr(ft_itoa_base(args, 10));
		}
		lst = lst->next;
	}
	va_end(args);
}



/*
- trouver fonction %p
- découper ce code là en plus petites fonctions
- tester
- cas d'erreurs
*/