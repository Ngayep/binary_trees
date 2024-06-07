#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_complete_recursive
	       (tree, 0, binary_tree_count_nodes(tree)));
}

/**
 * binary_tree_count_nodes - counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count
 *
 * Return: The number of nodes in the tree
 */
size_t binary_tree_count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_count_nodes(tree->left) +
		binary_tree_count_nodes(tree->right));
}

/**
 * binary_tree_is_complete_recursive - checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete_recursive(const binary_tree_t *tree,
				      size_t index, size_t node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (binary_tree_is_complete_recursive
		(tree->left, 2 * index + 1, node_count) && binary_tree_is_complete_recursive
		(tree->right, 2 * index + 2, node_count));
}
