#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data,
		int (*cmp)(void *, void *))
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = ft_create_elem(data);
	if (new_elem == NULL)
		return ;
	if (*begin_list == NULL || (*cmp)(data, (*begin_list)->data) <= 0)
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
		return ;
	}
	current = *begin_list;
	while (current->next != NULL && (*cmp)(data, current->next->data) > 0)
	{
		current = current->next;
	}
	new_elem->next = current->next;
	current->next = new_elem;
}
