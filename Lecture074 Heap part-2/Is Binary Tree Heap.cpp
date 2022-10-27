// Is Binary Tree Heap
// In this question, our task is to check whether the given binary tree is a heap or not.
// if it is a complete binary tree and all the nodes follow the heap property then it is a heap.

// step 1: check whether the given binary tree is a complete binary tree or not.
// step 2: if it is a complete binary tree then check whether all the nodes follow the heap property or not.
// if both steps are true then it is a heap and return true otherwise false;

// case of complete binary tree:
//** because every current node index is less than sizeOfTree in 0 based indexing.
// 1. take index and sizeOfTree.
// 2. if index is exceeding the size of the tree then return false.
// 3. and check left and right subtree recursively.

// case of max heap:
// 1. if the node is a leaf node or null then it is a max heap.
// 2. if node have only left child then check whether the node is greater than the left child or not.
// 3. if the node is not a leaf node then check whether the node is greater than its left and right child or not if it is greater then it is a max heap otherwise not.
// 4. and to check left and right subtree is a max heap or not if both are max heap then it is a max heap otherwise not.

class Solution
{
public:
    bool maxHeap(struct Node *root)
    {
        if (root == NULL)
            return true;

        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        if (root->right == NULL && root->left != NULL)
        {
            return root->data > root->left->data;
        }
        else
        {
            return ((root->data > root->left->data) && (root->data > root->right->data));
        }

        return maxHeap(root->left) && maxHeap(root->right);
    }
    int totalCount(struct Node *root)
    {
        if (root == NULL)
            return 0;

        return totalCount(root->right) + totalCount(root->left) + 1;
    }
    bool isCBT(struct Node *root, int i, int size)
    {
        if (root == NULL)
            return true;

        if (i >= size)
            return false;

        bool l = isCBT(root->left, 2 * i + 1, size);
        bool r = isCBT(root->right, 2 * i + 2, size);

        return l && r;
    }
    bool isHeap(struct Node *tree)
    {
        int size = totalCount(tree);

        if (isCBT(tree, 0, size) && maxHeap(tree))
        {
            return true;
        }

        return false;
    }
};
