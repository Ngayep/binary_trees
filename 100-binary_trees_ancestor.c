#include "binary_trees.h"

/**
 * binary_tree_t *binary_trees_ancestor - Finds the lowest common ancestor.
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: Pointer to a owest common ancestor node of the given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second || first == second->parent)
		return ((binary_tree_t *)first);
	if (second == first->parent)
		return ((binary_tree_t *)second);

	binary_tree_t *left = binary_trees_ancestor(first->left, second->left);
	binary_tree_t *right = binary_trees_ancestor
			       (first->right, second->right);

	if (left && right)
		return ((binary_tree_t *)first);

	if (left)
		return (left);

	if (right)
		return (right);

	return (NULL);
}

