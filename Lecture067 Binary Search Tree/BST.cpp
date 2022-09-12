#include "BST Node.h"

BNode *insert_into_bst(BNode *root,int data)
{

    if (root == NULL)
    {
        root = new BNode(data);
        return root;
    }
    if (data < root->data)
        root->left = insert_into_bst(root->left,data);
    else
        root->right = insert_into_bst(root->right,data);

    return root;
}
BNode *buildTree()
{
    BNode *root = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insert_into_bst(root,data);
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
int main()
{

    BNode *root = buildTree();
    print(root);
    return 0;
}