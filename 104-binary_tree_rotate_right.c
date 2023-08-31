#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return:  pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	temp = tree->left;
	tree->left = temp->right;
	if (temp->right != NULL)
	{
		temp->right->parent = tree;
	}
	temp->right = tree;
	temp->parent = tree->parent;
	tree->parent = temp;
	return (temp);
}
