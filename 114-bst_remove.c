#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * bst_remove -  removes a node from a Binary Search Tree
 * @root:  a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return:  pointer to the new root node of the tree after
 *	removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *successor;

	if (root == NULL)
		return (root);
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		return (root);
	}

	/* value has one child */
	if (!root->left)
	{
		temp = root->right;
		free(root);
		return (temp);
	}
	else if (!root->right)
	{
		temp = root->left;
		free(root);
		return (temp);
	}
	else /* has all children */
	{
		successor = root->right;
		while (successor->left)
			successor = successor->left;
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
