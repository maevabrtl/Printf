#include "../libftprintf.h"

char	*ft_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (s[0] == 'c')
		return (s + 2);
	return (s);
}