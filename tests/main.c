#include "libftprintf.h"
#include <stdio.h>

int main ()
{
	void *ptr;

	printf("%%");

	printf("%p %p %p %p %p %p %p\n", ptr, 'y', 2147483647, NULL, -2147483648, "asdfghj");
	ft_printf("%p %p %p %p %p %p %p\n", ptr, 'y', 2147483647, NULL, -2147483648, "asdfghj");

	printf("%c %c %c %c %c %c %c\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);
	ft_printf("%c %c %c %c %c %c %c\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);

	printf("%s %s %s %s %s %s %s\n", "asdfghj", 'y', 2147483647, NULL, -2147483648, 8.9, ptr);
	ft_printf("%s %s %s %s %s %s %s\n", "asdfghj", 'y', 2147483647, NULL, -2147483648, 8.9, ptr);

	printf("%s\n", "adfgdsWER");
	ft_printf("%s\n", "adfgdsWER");

	printf("%d %d %d %d %d %d %d\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);
	ft_printf("%d %d %d %d %d %d %d\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);

	printf("%i %i %i %i %i %i %i\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);
	ft_printf("%i %i %i %i %i %i %i\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);

	printf("%u %u %u %u %u %u %u\n", 'y', 2147483647, -156, -2147483648, "asdfghj", 8.9, ptr);
	ft_printf("%u %u %u %u %u %u %u\n", 'y', 2147483647, -156, -2147483648, "asdfghj", 8.9, ptr);

	printf("%x %x %x %x %x %x %x\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);
	ft_printf("%x %x %x %x %x %x %x\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);

	printf("%X %X %X %X %X %X %X\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);
	ft_printf("%X %X %X %X %X %X %X\n", 'y', 2147483647, NULL, -2147483648, "asdfghj", 8.9, ptr);

	ft_printf("%%  %  %%%\n");

	return (0);
}
