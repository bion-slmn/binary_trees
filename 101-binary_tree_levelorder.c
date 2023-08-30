#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#define MAX_SIZE 100
/**
 * binary_tree_levelorder - goes thru a binary tree with level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	binary_tree_t **queue = createQue();
	const binary_tree_t *temp = tree;

	if (!tree || !func || !queue)
		return;

	while (temp)
	{
		func(temp->n);

		/* enque the children */
		if (temp->left)
			enQueue(queue, &rear, temp->left);
		if (temp->right)
			enQueue(queue, &rear, temp->right);

		/*deque the queue */
		temp = deQueue(queue, &front);
	}
	free_Q(queue);
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
/**
 * free_Q - free memory
 * @que: the que to be freed
 */
void free_Q(binary_tree_t **que)
{
	int i = 0;

	for (; i < MAX_SIZE; i++)
	{
		if (que[i] != NULL)
			free(que[i]);
	}
	free(que);
}
