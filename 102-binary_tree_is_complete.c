#include <stdlib.h>
#include "binary_trees.h"
#define MAX_SIZE 100

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if success
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int no_node = countNodes((binary_tree_t *)tree);

	if (!tree)
		return (0);

	return (checkComplete((binary_tree_t *)tree, 0, no_node));
}
/**
 * countNodes - counts the number of nodes
 * @tree: is the root node
 * Return: a number
 */
int countNodes(binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (countNodes(tree->left) + countNodes(tree->right) + 1);
}
/**
 * checkComplete - checks that a tree is complete
 * @index: is the index of the parent
 * @numberNodes: the total number of nodes
 * @tree: root of the binary tree
 * Return: 1 on success or 0 on failure
 */
int checkComplete(binary_tree_t *tree, int index, int numberNodes)
{
	if (!tree || numberNodes == 0)
		return (1);

	if (index >= numberNodes)
		return (0);
	return (checkComplete(tree->left, 2 * index + 1, numberNodes) &&
			checkComplete(tree->right, 2 * index + 2, numberNodes));
}
