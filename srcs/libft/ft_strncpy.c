#include "libftprintf.h"

void	ft_strncpy(char *dst, const char *src, int n)
{
	dst[n] = '\0';
	n--;
	while (n >= 0)
	{
		dst[n] = src[n];
		n--;
	}
}