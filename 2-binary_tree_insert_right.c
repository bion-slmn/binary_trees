#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right -  inserts node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* create node */
	binary_tree_t *node, *temp;

	node = malloc(sizeof(binary_tree_t));
	if (!node || !parent)
		return (NULL);
	node->n = value;
	node->right = NULL;
	node->right = NULL;
	node->parent = parent;

	/* set the new node as the child */
	if (parent->right)
	{
		temp = parent->right;
		parent->right = node;
		node->right = temp;
		temp->parent = node;
	}
	else
	{
		parent->right = node;
	}

	return (node);
}
