#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (1 + (left_height > right_height ? left_height : right_height));

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
