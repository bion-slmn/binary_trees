#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first:  pointer to the first node
 * @second:  pointer to the second node
 * Return: pointer to the lowest common ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *f[100], *s[100];
	const binary_tree_t *temp, *temp1;
	int i = 1, j = 1;

	temp = first;
	f[0] = (binary_tree_t *)temp;

	while (temp->parent != NULL)
	{
		f[i] = temp->parent;
		temp = temp->parent;
		i++;
	}

	temp1 = second;
	s[0] = (binary_tree_t *) temp1;
	while (temp1->parent != NULL)
	{
		s[j] = temp1->parent;
		temp1 = temp1->parent;
		j++;
	}
	i = 0;

	while (f[i])
	{
		j = 0;
		while (s[j])
		{
			if (f[i] == s[j])
				return (f[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
