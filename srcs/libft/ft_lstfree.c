#include "libftprintf.h"

int		ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	if (lst != NULL)
		return (1);
	return (0);
}