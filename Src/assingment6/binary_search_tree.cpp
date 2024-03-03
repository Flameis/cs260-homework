#include "binary_search_tree.h"
#include <iostream>

// New values insertted left when less-than or right when greater-than-or-equal-to
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// Get Root
BinaryNode* BinarySearchTree::get_root() {
    return root;
}

/**
 * @struct BinaryNode
 * @brief Represents a node in a binary search tree.
 */
BinaryNode *BinarySearchTree::locate_parent(int proposed_value) {
    // Check if the tree is empty
    if(root == nullptr) {
        return nullptr;
    }

    // Start searching from the root
    BinaryNode *current = root;
    while(current->left != nullptr || current->right != nullptr) {
        // If the proposed value is less than the current node's value and the left child is null
        if(proposed_value < current->value && current->left == nullptr) {
            break;
        // If the proposed value is greater than or equal to the current node's value and the right child is null
        } else if (proposed_value >= current->value && current->right == nullptr) {
            break;
        // If the proposed value is less than the current node's value
        } else if(proposed_value < current->value) {
            current = current->left;
        // If the proposed value is greater than or equal to the current node's value
        } else {
            current = current->right;
        }
    }

    // Return the parent node
    return current;
}

/**
 * @brief Adds a new value to the binary search tree.
 * @param new_value The new value to be added to the binary search tree.
 */
void BinarySearchTree::add(int new_value) {
    // create new node
    BinaryNode *new_node = new BinaryNode{new_value, nullptr, nullptr};

    if(root == nullptr) {
        //assign root to that node
        root = new_node;
    } else {
        // find where it goes
        BinaryNode *parent = locate_parent(new_value);
        //update parent pointer
        if(new_value < parent->value) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }
}

/**
 * @brief Removes a value from the binary search tree.
 * @param old_value The value to be removed from the binary search tree.
 * @return The value that was removed from the binary search tree. If the value is not found, return -1.
 */
int BinarySearchTree::remove(int old_value) {
    // Check if the tree is empty
    if (root == nullptr) {
        return -1;
    }

    // Find the node to be removed
    BinaryNode *current = root;
    BinaryNode *parent = nullptr;
    while (current != nullptr && current->value != old_value) {
        parent = current;
        if (old_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node is not found, return -1
    if (current == nullptr) {
        return -1;
    }

    // Case 1: Node has no children
    if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
            root = nullptr;
        } else if (current == parent->left) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    }
    // Case 2: Node has one child
    else if (current->left == nullptr) {
        // If the node is the root
        if (current == root) {
            root = current->right;
        // If the node is a left child
        } else if (current == parent->left) {
            parent->left = current->right;
        // If the node is a right child
        } else {
            parent->right = current->right;
        }
        delete current;
    // If the node has a left child
    } else if (current->right == nullptr) {
        if (current == root) {
            root = current->left;
        } else if (current == parent->left) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    }
    // Case 3: Node has two children
    else {
        // Find the successor of the node to be removed
        BinaryNode *successor = current->right;
        BinaryNode *successorParent = current;
        // Find the leftmost node in the right subtree
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }
        // Replace the value of the node to be removed with the value of the successor
        current->value = successor->value;
        if (successor == successorParent->left) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        delete successor;
    }

    return old_value;
}

/**
 * @brief Searches for a value in the binary search tree.
 * @param proposed_value The value to be searched for in the binary search tree.
 * @return True if the value is found in the binary search tree, false otherwise.
 */
bool BinarySearchTree::search(int proposed_value) {
    // Check if the tree is empty
    if (root == nullptr) {
        return false;
    }

    // Start searching from the root
    BinaryNode *current = root;
    while (current != nullptr) {
        if (proposed_value == current->value) {
            return true;
        } else if (proposed_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}

/**
 * @brief Traverses the binary search tree in pre-order.
 * @param node The current node being processed.
 */
void BinarySearchTree::pre_order_traversal(BinaryNode* node) {
    if (node == nullptr) {
        return;
    }

    // Process the current node
    std::cout << node->value << " ";

    // Recursively traverse the left subtree
    pre_order_traversal(node->left);

    // Recursively traverse the right subtree
    pre_order_traversal(node->right);
}

/**
 * @brief Traverses the binary search tree in post-order.
 * @param node The current node being processed.
 */
void BinarySearchTree::post_order_traversal(BinaryNode* node) {
    if (node == nullptr) {
        return;
    }

    // Recursively traverse the left subtree
    post_order_traversal(node->left);

    // Recursively traverse the right subtree
    post_order_traversal(node->right);

    // Process the current node
    std::cout << node->value << " ";
}

/**
 * @brief Traverses the binary search tree in in-order.
 * @param node The current node being processed.
 */
void BinarySearchTree::in_order_traversal(BinaryNode* node) {
    if (node == nullptr) {
        return;
    }

    // Recursively traverse the left subtree
    in_order_traversal(node->left);

    // Process the current node
    std::cout << node->value << " ";

    // Recursively traverse the right subtree
    in_order_traversal(node->right);
}

// Main function for the program
int main() {
    // Create a binary search tree object
    BinarySearchTree bst;

    // Add values to the binary search tree
    bst.add(5);
    bst.add(3);
    bst.add(7);
    bst.add(2);
    bst.add(4);
    bst.add(6);
    bst.add(8);

    // Test the in_order_traversal function to see if elements were added in order
    std::cout << "In-order traversal: ";
    bst.in_order_traversal(bst.get_root());
    std::cout << std::endl;

    // Test the search function
    int value = 6;
    if (bst.search(value)) {
        std::cout << value << " is found in the binary search tree." << std::endl;
    } else {
        std::cout << value << " is not found in the binary search tree." << std::endl;
    }

    value = 9;
    if (bst.search(value)) {
        std::cout << value << " is found in the binary search tree." << std::endl;
    } else {
        std::cout << value << " is not found in the binary search tree." << std::endl;
    }

    // Test the remove function
    value = 4;
    if (bst.remove(value) != -1) {
        std::cout << value << " is removed from the binary search tree." << std::endl;
    } else {
        std::cout << value << " is not found in the binary search tree." << std::endl;
    }

    value = 9;
    if (bst.remove(value) != -1) {
        std::cout << value << " is removed from the binary search tree." << std::endl;
    } else {
        std::cout << value << " is not found in the binary search tree." << std::endl;
    }

    // Test the traversal functions
    std::cout << "Pre-order traversal: ";
    bst.pre_order_traversal(bst.get_root());
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.post_order_traversal(bst.get_root());
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    bst.in_order_traversal(bst.get_root());
    std::cout << std::endl;

    return 0;
}