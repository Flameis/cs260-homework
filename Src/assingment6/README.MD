## Binary Search Tree Design

### Node Structure:
- `value`: The value stored in the node
- `left`: Pointer to the left child node
- `right`: Pointer to the right child node

### Operations:
- `get_root()`: Gets the Root node
- `locate_parent(value)`: Find the node that would be the parent of the value
- `insert(value)`: Inserts a new node with the given value into the tree
- `search(value)`: Searches for a node with the given value in the tree
- `delete(value)`: Deletes a node with the given value from the tree
- `traverse()`: Traverses the tree in a specific order (e.g., in-order, pre-order, post-order)

### Functions:

#### Add:
1. If the tree is empty, create a new node with the given value and make it the root.
2. If the value is less than the current node's value, go to the left subtree.
3. If the value is greater than the current node's value, go to the right subtree.
4. Repeat steps 2-3 until finding an empty spot.
5. Insert the new node at the empty spot.

#### Remove:
1. Search for the node with the given value.
2. If the node is not found, return.
3. If the node has no children, remove it.
4. If the node has one child, replace the node with its child.
5. If the node has two children, find the minimum value in the right subtree (or maximum value in the left subtree), replace the node's value with it, and delete the duplicate value from the subtree.

#### Searching:
1. Start at the root node.
2. If the value is equal to the current node's value, return the node.
3. If the value is less than the current node's value, go to the left subtree.
4. If the value is greater than the current node's value, go to the right subtree.
5. Repeat steps 2-4 until finding the node or reaching a leaf node.
6. If the node is not found, return null.

#### Traversal:
- In-order traversal: Visit the left subtree, visit the current node, visit the right subtree.
- Pre-order traversal: Visit the current node, visit the left subtree, visit the right subtree.
- Post-order traversal: Visit the left subtree, visit the right subtree, visit the current node.

### Tests:
1. Add numbers to the binary tree based on our ordering rules
2. Check the order with in_order_traversal()
3. Test the search function, see if a value is detected in the tree and see if a wrong value is detected
4. Test the remove function and see if an item is successfully removed
5. Test the traversal functions and see if the order is correct and all elements are as they should be