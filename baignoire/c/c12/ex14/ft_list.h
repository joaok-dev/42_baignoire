#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

void	ft_list_sort(t_list *begin_list, int (*cmp)(void *, void *));

#endif // !FT_LIST_H

