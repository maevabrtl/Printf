#include "libftprintf.h"

t_list	*maketolist(char *str, t_list *lst)
{
	lst->next = ft_lstnew(str);
	lst = lst->next;
	return (lst)
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


/* useless

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
		arglist = arglist->next;
		nbargs--;
	}
	va_end(args);
	return (arglist)
}*/