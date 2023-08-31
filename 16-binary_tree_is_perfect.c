#include "binary_trees.h"

/**
 * tree_is_perfect - checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to be checked.
 * Return: 0 if perfect or 1 if otherwise.
 */

int tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree->left && tree->right)
	{
		left = 1 + tree_is_perfect(tree->left);
		right = 1 + tree_is_perfect(tree->right);
		if (left == right && left !=0 && right !=0)
			return (left);
		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree exist and it is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 0 if succesful and 1 if fail.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
		return (0);
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
			return (1);
		return (0);
	}
}
