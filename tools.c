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