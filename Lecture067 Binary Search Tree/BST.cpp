#include "BST Node.h"

BNode *insert_into_bst(BNode *root, int data)
{

    if (root == NULL)
    {
        root = new BNode(data);
        return root;
    }
    if (data < root->data)
        root->left = insert_into_bst(root->left, data);
    else
        root->right = insert_into_bst(root->right, data);

    return root;
}
BNode *buildTree()
{
    BNode *root = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insert_into_bst(root, data);
        cin >> data;
    }

    return root;
}
void print(BNode *root)
{
    if (root == NULL)
        return;
    queue<BNode *> pending;
    pending.push(root);

    while (!pending.empty())
    {
        int n = pending.size();

        for (int i = 1; i <= n; i++)
        {
            BNode *curr = pending.front();

            cout << curr->data << " ";

            if (curr->left != NULL)
                pending.push(curr->left);
            if (curr->right != NULL)
                pending.push(curr->right);

            pending.pop();
        }
        cout << endl;
    }
}
int MinVal(BNode *root)
{
    BNode *ptr = root;

    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr->data;
}
int MaxVal(BNode *root)
{
    BNode *ptr = root;

    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr->data;
}
bool SearchInBST(BNode *root, int x)
{
    BNode *ptr = root;

    while (ptr != NULL)
    {
        if (ptr->data == x)
        {
            return true;
        }
        else if (x < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return false;
}
bool isInorderPressers(BNode *root, int x)
{
    if (root == NULL)
        return false;
    return root->data == x;
}
int inorderPressers(BNode *root, int x)
{
    BNode *ptr = root;

    while (ptr != NULL)
    {
        if (x < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
        if (isInorderPressers(ptr->left, x))
        {
            return ptr->data;
        }
        if (isInorderPressers(ptr->right, x))
        {
            return ptr->data;
        }
    }
    return -1;
}
void Inorder(BNode *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

BNode *findMinVal(BNode *root)
{
    BNode *ptr = root;

    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

BNode *deleteNodeBST(BNode *root, int t)
{
    if (root == NULL)
        return root;

    if (root->data == t)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // root have only left part
        if (root->left != NULL && root->right == NULL)
        {
            BNode *temp = root->left;
            delete root;
            return temp;
        }
        // root have only right part
        if (root->right != NULL && root->left == NULL)
        {
            BNode *temp = root->right;
            delete root;
            return temp;
        }
        // root have both part
        if (root->right != NULL && root->left != NULL)
        {
            int minValFromRight = findMinVal(root->right)->data;
            root->data = minValFromRight;
            root->right = deleteNodeBST(root->right, minValFromRight);
            return root;
        }
    }
    else if (t < root->data)
    {
        root->left = deleteNodeBST(root->left, t);
        return root;
    }
    else
    {
        root->right = deleteNodeBST(root->right, t);
        return root;
    }
    return root;
}

int main()
{

    BNode *root = buildTree();
    print(root);
    // 50 20 70 10 30 90 110 -1
    // cout << "Min Value : " << MinVal(root) << endl;
    // cout << "Max Value : " << MaxVal(root) << endl;
    // cout << "Find Index : " << SearchInBST(root, 30) << endl;
    // cout << "Inorder Pressers : " << inorderPressers(root, 30) << endl;
    root = deleteNodeBST(root, 50);
    print(root);
    Inorder(root);

    return 0;
}