#include "TreeNode.h"

TreeNode<int> *buildTreeLevel()
{
    int data;
    queue<TreeNode<int> *> pendingNode;
    cout << "Enter the root Node data : ";
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    pendingNode.push(root);

    while (!pendingNode.empty())
    {
        TreeNode<int> *currNode = pendingNode.front();
        int childData;
        cout << "Enter the child of " << currNode->data << " : ";
        cin >> childData;

        while (childData != -1)
        {
            TreeNode<int> *newNode = new TreeNode<int>(childData);
            currNode->children.push_back(newNode);
            pendingNode.push(newNode);
            cin >> childData;
        }
        pendingNode.pop();
    }
    return root;
}
TreeNode<int> *buildTree()
{
    int data, numChild;
    cout << "Enter the data: ";
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    cout << "Enter the Number of child for " << root->data << " : ";
    cin >> numChild;
    for (int i = 0; i < numChild; i++)
    {
        cout << "Enter the Child of " << i + 1 << " for " << root->data << " ";

        root->children.push_back(buildTree());
    }
    return root;
}

void print(TreeNode<int> *root)
{

    cout << root->data << ":";
    for (auto i : root->children)
    {
        cout << i->data << ",";
    }
    cout << endl;
    for (auto i : root->children)
    {
        print(i);
    }
}
void printLevel(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        TreeNode<int> *currNode = pendingNode.front();
        cout << currNode->data << " : ";
        for (auto i : currNode->children)
        {
            cout << i->data << ",";
            pendingNode.push(i);
        }
        cout << endl;

        pendingNode.pop();
    }
}

int main()
{
    TreeNode<int> *root = NULL;
    // TreeNode<int> *c1 = new TreeNode<int>(20);
    // TreeNode<int> *c2 = new TreeNode<int>(30);
    // TreeNode<int> *c3 = new TreeNode<int>(40);

    // root->children.push_back(c1);
    // root->children.push_back(c2);
    // c1->children.push_back(c3);
    // root = buildTree();
    root = buildTreeLevel();
    // print(root);
    printLevel(root);
    cout << "sab changa se";
    return 0;
}