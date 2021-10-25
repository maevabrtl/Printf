#include "libftprintf.h"

// pr itoa_base
void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (ret = NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}