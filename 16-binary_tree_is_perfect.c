#include "binary_trees.h"
#include "9-binary_tree_height.c"

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
