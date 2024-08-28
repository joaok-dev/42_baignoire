#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr);

#endif // !FT_LIST_H
