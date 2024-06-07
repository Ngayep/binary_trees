#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor.
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: Pointer to a lowest common ancestor node of the given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *ptr1 = first, *ptr2 = second;

	if (!ptr1 || !ptr2)
		return (NULL);

	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->parent ? ptr1->parent : second;
		ptr2 = ptr2->parent ? ptr2->parent : first;
	}

	return ((binary_tree_t *)ptr1);
}
