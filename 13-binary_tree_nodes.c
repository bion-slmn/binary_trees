#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_nodes -  counts the nodes with at least 1 child
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (1 + left + right);
	return (left + right);
}
