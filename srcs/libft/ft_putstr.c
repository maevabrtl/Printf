#include "libftprintf.h"

void	putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, &(*str), 1);
		str++;
	}
}