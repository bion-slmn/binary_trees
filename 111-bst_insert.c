#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * bst_insert -  inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newnode, *node = *tree;

	if (tree != NULL)
	{
	if (*tree == NULL)
	{
		newnode = binary_tree_node(*tree, value);
		return (*tree = newnode);
	}

	if (value < node->n)
	{
		if (node->left)
			return (bst_insert(&node->left, value));
		newnode = binary_tree_node(node, value);
		return (node->left = newnode);
	}
	else if (value > node->n)
	{
		if (node->right)
			return (bst_insert(&(*tree)->right, value));
		newnode = binary_tree_node(node, value);
		return (node->right = newnode);
	}
	else
		return (NULL);
	}
	return (NULL);
}
