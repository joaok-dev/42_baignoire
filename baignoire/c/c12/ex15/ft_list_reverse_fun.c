#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;
	void	*temp_data;

	if (begin_list == NULL)
		return ;
	prev = NULL;
	current = begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	current = prev;
	while (current != NULL)
	{
		temp_data = current->data;
		current->data = prev->data;
		prev->data = temp_data;
		prev = prev->next;
		current = current->next;
	}
}
