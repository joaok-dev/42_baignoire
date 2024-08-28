#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

typedef struct	s_queue_node
{
	t_btree				*node;
	int					level;
	struct s_queue_node	*next;
}				t_queue_node;

void			btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

#endif
