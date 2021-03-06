#include "libftprintf.h"

void	ft_printf(char	*str, ...)
{
	t_list *lstfirst;
	va_list	args;
	int err;

	err = check_error(str);
	if (err == 1)
		error_exit(err);
	if (str && (!str[0]))
		exit(EXIT_SUCCESS);
	lstfirst = ft_cut(str);
	if (lstfirst == NULL)
		error_exit(2);
	va_start(args, str);
	handle_percent(lstfirst, args);
	ft_lstfree(lstfirst);
	va_end(args);
}

t_list	*ft_cut(char *str)
{
	t_list	*lst;
	t_list	*lstfirst;
	int		ct;

	lst = NULL;
	ct = 0;
	while (str[ct] != '\0')
	{
		if (lst != NULL)
			lst = ft_parse(str, &ct, lst);
		else
		{
			lst = ft_parse(str, &ct, lst);
			lstfirst = lst;
		}
		if (lstfirst == NULL || lst == NULL)
			return (NULL);
	}
	if (lstfirst != NULL)
		lst->next = NULL;
	return (lstfirst);
}

void	handle_percent(t_list *lst, va_list args)
{
	char	*ret;
	char	*content;
	
	ret = NULL;
	while (lst != NULL)
	{
		content = (char *)lst->content;
		if (content[0] != '%')
			ft_putstr(content);
		else if (content[1] == 's')
			ft_putstr((char *)va_arg(args, char *));
		else if (content[1] == 'c')
			ft_putchar((int)va_arg(args, int));
		else if (content[1] == '%')
			ft_putchar('%');
		else if (content[1] == 'p' || content[1] == 'x'
		|| content[1] == 'X' || content[1] == 'u')
			u_percent(lst, args, ret);
		else if (content[1] == 'd' || content[1] == 'i')
			i_percent(lst, args, ret);
		lst = lst->next;
	}
}

void	u_percent(t_list *lst, va_list args, char *ret)
{
	char	*content;

	content = (char *)lst->content;
	if (content[1] == 'p')
	{
		ft_putstr("0x");
		ret = utoa((size_t)va_arg(args, void *), 16, 0);
		ft_putstr(ret);
	}
	else if (content[1] == 'x')
	{
		ret = utoa((unsigned int)va_arg(args, unsigned int), 16, 0);
		ft_putstr(ret);
	}
	else if (content[1] == 'X')
	{
		ret = utoa((unsigned int)va_arg(args, unsigned int), 16, 1);
		ft_putstr(ret);
	}
	else if (content[1] == 'u')
	{
		ret = utoa((unsigned int)va_arg(args, unsigned int), 10, 0);
		ft_putstr(ret);
	}
	free(ret);
}

void	i_percent(t_list *lst, va_list args, char *ret)
{
	char	*content;

	content = (char *)lst->content;
	if (content[1] == 'i')
	{
		ret = ft_itoa_base((int)va_arg(args, int), 10);
		ft_putstr(ret);
	}
	else if (content[1] == 'd')
	{
		ret = ft_itoa_base((size_t)va_arg(args, size_t), 10);
		ft_putstr(ret);
	}
	free(ret);
}
