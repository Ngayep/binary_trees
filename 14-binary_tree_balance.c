#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or -1 if tree is NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right)

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}



/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
