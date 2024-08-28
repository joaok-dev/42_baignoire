#include "ft_btree.h"

static t_queue_node	*enqueue(t_queue_node *queue, t_btree *node, int level)
{
	t_queue_node	*new_node;
	t_queue_node	*temp;

	new_node = (t_queue_node *)malloc(sizeof(t_queue_node));
	if (!new_node)
		return (NULL);
	new_node->node = node;
	new_node->level = level;
	new_node->next = NULL;
	if (!queue)
		return (new_node);
	temp = queue;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return (queue);
}

static t_queue_node	*dequeue(t_queue_node *queue)
{
	t_queue_node	*next_node;

	if (!queue)
		return (NULL);
	next_node = queue->next;
	free(queue);
	return (next_node);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_queue_node	*queue;
	int				current_level;
	int				is_first_elem;

	if (!root)
		return ;
	queue = NULL;
	queue = enqueue(queue, root, 0);
	current_level = 0;
	is_first_elem = 1;
	while (queue)
	{
		if (queue->level > current_level)
		{
			current_level = queue->level;
			is_first_elem = 1;
		}
		applyf(queue->node->item, queue->level, is_first_elem);
		is_first_elem = 0;
		if (queue->node->left)
			queue = enqueue(queue, queue->node->left, queue->level + 1);
		if (queue->node->right)
			queue = enqueue(queue, queue->node->right, queue->level + 1);
		queue = dequeue(queue);
	}
}
