#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)(void *, void *))
{
	t_list	*current;

	if (begin_list2 == NULL)
		return ;
	if (*begin_list1 == NULL || (*cmp)(begin_list2->data,
			(*begin_list1)->data) <= 0)
	{
		current = begin_list2->next;
		begin_list2->next = *begin_list1;
		*begin_list1 = begin_list2;
		ft_sorted_list_merge(begin_list1, current, cmp);
	}
	else
		ft_sorted_list_merge(&(*begin_list1)->next, begin_list2, cmp);
}
