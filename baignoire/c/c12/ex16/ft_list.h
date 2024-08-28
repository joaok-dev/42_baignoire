#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

t_list		*ft_create_elem(void *data);
void		ft_sorted_list_insert(t_list **begin_list, void *data, 
			int (*cmp)(void *, void *));

#endif // !FT_LIST_H
