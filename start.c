#include "libftprintf.h"

t_list *f1(char *str)
{
	int		i;
	char	*snext;
	char	*stocopy;
	t_list	*lst;

	i = 0;
	snext = str;
	stocopy = NULL;
	lst = NULL;
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		snext = ft_strchr(snext, '%');
		stocopy = malloc(sizeof(char) * (snext - str) + 1);
		if (stocopy == NULL)
			return (NULL);
		ft_strncpy(stocopy, str, snext - str);
		if (lst == NULL)
			lst = ft_lstnew(stocopy);
		else
		{
			lst->next = ft_lstnew(stocopy);
			lst = lst->next;
		}
		str = snext;
	}
	return (lst);
}