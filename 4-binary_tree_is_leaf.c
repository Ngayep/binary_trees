#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 0 if node is NULL and 1 otherwise
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
