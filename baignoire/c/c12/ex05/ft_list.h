#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

t_list		*ft_create_elem(void *data);
t_list		*ft_list_push_strs(int size, char **strs);

#endif // !FT_LIST_H
