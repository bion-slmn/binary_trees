#include <stdlib.h>
#include "binary_trees.h"
#define MAX_SIZE 100
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if success
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front = 0, rear = 0, not_full = 0;
	binary_tree_t **que;
	const binary_tree_t *temp = tree;

	if (!tree)
		return (0);
	que = createQue();
	if (!que)
		return (0);
	enQueue(que, &rear, (binary_tree_t *)temp);
	while (front != rear)
	{
		temp = deQueue(que, &front);
		if (temp->left)
		{
			if (not_full == 1)
				return (0);
			enQueue(que, &rear, temp->left);
		}
		else
			not_full = 1;
		if (temp->right)
		{
			if (not_full == 1)
				return (0);
			enQueue(que, &rear, temp->right);
		}
		else
			not_full = 1;
	}
	return (1);

}
/**
 * createQue - create a queue
 * Return: a queue
 */
binary_tree_t **createQue()
{
	binary_tree_t **que = malloc(sizeof(binary_tree_t *) * MAX_SIZE);

	int i;

	if (!que)
		return (NULL);
	for (i = 0; i < MAX_SIZE; i++)
	{
		que[i] = NULL;
	}
	return (que);
}
/**
 * enQueue - adds a node to the que
 * @que: it the queue where the node is added
 * @rear: the pointer to the last node
 * @newnode: is the new node to be added
 */
void enQueue(binary_tree_t **que, int *rear, binary_tree_t *newnode)
{
	que[*rear] = newnode;
	(*rear)++;
}

/**
 * deQueue - removes the front node in a que
 * @que: is the queue from which a node is removed
 * @front: a pointer to the front of a a que
 * Return: the removed mode
 */
binary_tree_t *deQueue(binary_tree_t **que, int *front)
{
	(*front)++;
	return (que[*front - 1]);
}
