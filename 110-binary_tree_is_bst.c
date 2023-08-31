#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "binary_trees.h"
/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * @tree:  checks if a binary tree is a valid Binary Search Tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (isBST((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
/**
 * isBST - check if a tree is BST using range
 * @tree:  pointer to the root node of the tree to check
 * @min: is the min range of the value of node must be
 * @max: is the max range of the value of the node must be
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int isBST(binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (isBST(tree->left, min, tree->n - 1) &&
			isBST(tree->right, tree->n + 1, max));
	/* tightening of max and min are reduced and added to catch dups */
}
