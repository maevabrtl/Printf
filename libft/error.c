#include "../libftprintf.h"

int		check_error(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i += ft_strchr(&str[i], '%');
		if (str[i] == '\0')
			return (0);
		if (str[i] == '%')
			i++;
		if (str[i] != 'c' && str[i] != 's' && str[i] != 'p'
		&& str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
		&& str[i] != 'x' && str[i] != 'X' && str[i] != '%')
			return (1);
		if (str[i] == '%' && str[i - 1] == '%')
			i++;
	}
	return (0);
}

void	puterror(char *str)
{
	while (*str != '\0')
	{
		write(2, &(*str), 1);
		str++;
	}
}

void    error_exit(int n)
{
    if (n == 1)
        puterror("Error : Wrong format specifier. Supported ones are \"cspdiuxX%\".\n");
    if (n == 2)
        puterror("Error : Parsing failed. My bad.\n");
    exit(EXIT_FAILURE);
}