#include "libftprintf.h"

static int	nbrlen(int n, int base)
{
	int	nlen;

	nlen = 1;
	while (n / 10)
	{
		n /= 10;
		nlen++;
	}
	return (nlen);
}

static char	*intmin(char *r)
{
	ft_strlcpy(r, "-2147483648", 12);
	return (r);
}

static int	neg(int n, char *ret)
{
	ret[0] = '-';
	return (-n);
}

char		*ft_itoa_base(int n, int base)
{
	char	*ret;
	int		nlen;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	nlen = nbrlen(n, base);
	if (n < 0)
		nlen++;
	if (!(ret = (char *)ft_calloc(nlen + 1, sizeof(char))))
		return (0);
	if (n == -2147483648)
		return (intmin(ret));
	if (n < 0)
		n = neg(n, ret);
	if (n == 0)
		ret[0] = '0';
	i = nlen - 1;
	while (n)
	{
		ret[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (ret);
}