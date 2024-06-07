#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree *
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
 * is_perfect_recursive - checks if a binary tree is perfect recursively
 * @tree: pointer to the root node of the tree to check
 * @depth: depth of the tree
 * @level: current level in the tree
 * Return: 1 if tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (depth == level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return ((is_perfect_recursive(tree->left, depth, level + 1)) &&
			(is_perfect_recursive(tree->right, depth, level + 1)));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t depth = binary_tree_height(tree);

	return (is_perfect_recursive(tree, depth, 0));
}
