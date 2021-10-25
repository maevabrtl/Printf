#include "libftprintf.h"

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