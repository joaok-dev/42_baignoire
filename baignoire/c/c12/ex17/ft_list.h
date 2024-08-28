#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

void		ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, 
			int (*cmp)(void *, void *));

#endif // !FT_LIST_H
