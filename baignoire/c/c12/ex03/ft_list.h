
#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

t_list		*ft_list_last(t_list *begin_list);

#endif // !FT_LIST_H
