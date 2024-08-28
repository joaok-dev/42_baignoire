#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*temp;

	while (*begin_list != NULL && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(temp->data);
		free(temp);
	}
	current = *begin_list;
	while (current != NULL && current->next != NULL)
	{
		if ((*cmp)(current->next->data, data_ref) == 0)
		{
			temp = current->next;
			current->next = current->next->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		else
			current = current->next;
	}
}
