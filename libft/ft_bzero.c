#include "libftprintf.h"

// pr itoa_base
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