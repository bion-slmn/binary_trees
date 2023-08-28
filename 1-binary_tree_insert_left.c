#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left -  inserts node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* create node */
	binary_tree_t *node, *temp;

	node = malloc(sizeof(binary_tree_t));
	if (!node || !parent)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	/* set the new node as the child */
	if (parent->left)
	{
		temp = parent->left;
		parent->left = node;
		node->left = temp;
		temp->parent = node;
	}
	else
	{
		parent->left = node;
	}

	return (node);
}
