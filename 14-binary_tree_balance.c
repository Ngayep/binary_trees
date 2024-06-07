#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_height, right_height;

	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	else
		left_height = 0;

	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;
	else
		right_height = 0;

	return (left_height - right_height);
}
