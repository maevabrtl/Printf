#include "libftprintf.h"
#include <stdio.h>

int main ()
{
	t_list *list;
	list = f1("bonjour %c\n", 'g');
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
}