struct BinaryNode
{
    int value;
    BinaryNode *left;
    BinaryNode *right;
};

class BinarySearchTree {
    BinaryNode *root;
    BinaryNode *locate_parent(int proposed_value);

    public:
        BinarySearchTree();
        void add(int new_value);
        int remove(int old_value);
        bool search(int proposed_value);

        BinaryNode* get_root();

        void in_order_traversal(BinaryNode* node);
        void pre_order_traversal(BinaryNode* node);
        void post_order_traversal(BinaryNode* node);
};