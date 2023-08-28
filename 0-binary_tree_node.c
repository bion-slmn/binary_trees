#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - create a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* create a node */
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;

	return (node);
}
