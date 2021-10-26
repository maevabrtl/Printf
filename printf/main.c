#include "../libftprintf.h"
#include <stdio.h>

int main ()
{
	ft_printf("bonjour %d, bonjour\n", 12);
	return (0);
}


/*int main ()
{
	t_list *list;
	list = f1("bonjour %i\n", 12);
	if (list == NULL)
		return (0);
	printf("%s\n", list->content);
	if (list->next != NULL)
		list = list->next;
	while (list->next != NULL)
	{
		printf("%s\n", list->content);
		if (list->next != NULL)
			list = list->next;
	}
	return (0);
}*/