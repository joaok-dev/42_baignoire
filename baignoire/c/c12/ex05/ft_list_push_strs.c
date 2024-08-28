#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*new_elem;

	list = NULL;
	while (size > 0)
	{
		new_elem = ft_create_elem(*(strs + size - 1));
		if (new_elem != NULL)
		{
			new_elem->next = list;
			list = new_elem;
		}
		size--;
	}
	return (list);
}
