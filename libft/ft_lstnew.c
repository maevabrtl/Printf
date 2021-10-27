#include "../libftprintf.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;
	int		size;

	size = ft_strlen(content);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->next = 0;
	new->content = malloc(sizeof(char) * (size + 1));
	if (new->content == NULL)
		return (NULL);
	ft_strncpy(new->content, content, size);
	return (new);
}