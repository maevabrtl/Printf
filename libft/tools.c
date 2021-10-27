#include "../libftprintf.h"

int		find_percent_index(char *str, int si)
{
	int i;

	i = 0;
	if (str[si] != '%')
		i = ft_strchr(&str[si], '%');
	else
		i = 2;
	return (i);
}


t_list	*maketolist(char *str, t_list *lst)
{
	lst->next = ft_lstnew(str);
	lst = lst->next;
	return (lst);
}


t_list	*ft_parse(char *str, int *ct, t_list *lst, t_list *lstfirst)
{
	int		i;
	char	*stocopy;

	i = find_percent_index(str, *ct);
	stocopy = malloc(sizeof(char) * i + 1);
	if (stocopy == NULL)
		return (NULL);
	ft_strncpy(stocopy, &str[*ct], i);
	if (lst == NULL)
		lst = ft_lstnew(stocopy);
	else
		lst = maketolist(stocopy, lst);
	if (lst == NULL)
		return (NULL);
	*ct += i;
	free(stocopy);
	return (lst);
}