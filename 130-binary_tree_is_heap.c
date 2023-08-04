#include  "binary_trees.h"

int is_complete_tree(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	/*Recursively check the left and right subtrees*/
	return (is_complete_tree(tree->left, 2 * index + 1, node_count) &&
		is_complete_tree(tree->right, 2 * index + 2, node_count));
}


int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	/*Check the Max Heap property for the current node*/
	if (tree->left != NULL && tree->n < tree->left->n)
		return (0);

	if (tree->right != NULL && tree->n < tree->right->n)
		return (0);

	/*Recursively check the left and right subtrees*/
	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}


int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*Count the total number of nodes in the tree*/
	int node_count = 0;
	const binary_tree_t *current = tree;

	while (current != NULL)
	{
		node_count++;
		current = current->right;
	}

	/*Check if tree is a complete binary tree and meets the Max Heap property*/
	return (is_complete_tree(tree, 0, node_count) && is_max_heap(tree));
}
