#include "ft_list.h"

void	ft_list_sort(t_list *begin_list, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*next;
	void	*temp_data;

	if (begin_list == NULL)
		return ;
	current = begin_list;
	while (current != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if ((*cmp)(current->data, next->data) > 0)
			{
				temp_data = current->data;
				current->data = next->data;
				next->data = temp_data;
			}
			next = next->next;
		}
		current = current->next;
	}
}
