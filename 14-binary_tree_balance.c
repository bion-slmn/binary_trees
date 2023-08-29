#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_heigh - measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: An integer.
 */
int binary_tree_heigh(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	left = binary_tree_heigh(tree->left);
	right = binary_tree_heigh(tree->right);

	return (((left > right) ? left : right) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);
	l_height = binary_tree_heigh(tree->left);
	r_height = binary_tree_heigh(tree->right);

	return (l_height - r_height);
}
