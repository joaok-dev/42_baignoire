#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_count;
	int	right_count;

	if (root == NULL)
		return (0);
	left_count = btree_level_count(root->left);
	right_count = btree_level_count(root->right);
	if (left_count > right_count)
		return (left_count + 1);
	else
		return (right_count + 1);
}
