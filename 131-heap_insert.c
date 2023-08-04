#include "binary_trees.h"

// Function to create a new heap node
static heap_t* create_node(int value) {
    heap_t* new_node = (heap_t*)malloc(sizeof(heap_t));
    if (new_node != NULL) {
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

// Function to swap the values of two nodes
static void swap_values(heap_t* node1, heap_t* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Function to insert a value into the Max Heap
heap_t* heap_insert(heap_t** root, int value) {
    // Create a new node with the given value
    heap_t* new_node = create_node(value);
    if (new_node == NULL) {
        return NULL; // Memory allocation failure
    }

    if (*root == NULL) {
        *root = new_node; // If the root is NULL, make the new node the root
        return new_node;
    }

    // Insert the node at the bottom level, maintaining the complete binary tree property
    // and then fix the Max Heap ordering by swapping nodes if necessary
    heap_t* current = *root;
    while (1) {
        if (current->left == NULL) {
            current->left = new_node;
            break;
        } else if (current->right == NULL) {
            current->right = new_node;
            break;
        }

        // Go to the next level to insert the new node
        if (current->left != NULL && current->right != NULL) {
            if (current->left->left == NULL || current->left->right == NULL) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }

    // Fix the Max Heap ordering by swapping nodes if necessary
    while (new_node->data > current->data) {
        swap_values(new_node, current);
        if (current == *root) {
            break;
        }
        current = current->parent;
    }

    return new_node;
}
