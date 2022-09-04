#include "binaryNode.h"
BNode<int> *buildTree()
{
    int data;
    // cout << "Enter the root data";
    cin >> data;

    BNode<int> *root = new BNode<int>(data);
    if (data == -1)
        return NULL;
    cout << "Enter data for left " << data << " : " << endl;
    root->left = buildTree();
    cout << "Enter data for right " << data << " : " << endl;
    root->right = buildTree();
    return root;
}
BNode<int> *buildTreeLevel()
{
    queue<BNode<int> *> pendingNode;
    int data;
    cout << "Enter the root data : ";
    cin >> data;
    BNode<int> *root = new BNode<int>(data);
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        BNode<int> *currentNode = pendingNode.front();
        pendingNode.pop();

        int leftData;
        int rightData;
        cout << "Enter the left data of " << currentNode->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            BNode<int> *newNode = new BNode<int>(leftData);
            currentNode->left = newNode;
            pendingNode.push(newNode);
        }

        cout << "Enter the right data of " << currentNode->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            BNode<int> *newNode = new BNode<int>(rightData);
            currentNode->right = newNode;
            pendingNode.push(newNode);
        }
    }
    return root;
}

void printLevel(BNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        BNode<int> *currentNode = pendingNode.front();
        cout << currentNode->data << ":";
        pendingNode.pop();

        if (currentNode->left != NULL)
        {
            cout << currentNode->left->data << ",";
            pendingNode.push(currentNode->left);
        }
        if (currentNode->right != NULL)
        {
            cout << currentNode->right->data << ",";
            pendingNode.push(currentNode->right);
        }
        cout << endl;
    }
}

void inorder(BNode<int> *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


//** postorderTraversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        vector<int> ans;
        if(root == NULL)
            return ans;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);

          
            if(curr->left != NULL)
              s1.push(curr->left);
            if(curr->right != NULL)
              s1.push(curr->right);

        }
        
        while(!s2.empty()){
            TreeNode* curr = s2.top();
            s2.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};

void iterativePreorder(node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty stack and push root to it
    stack<node*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

int main()
{

    BNode<int> *root = NULL;
    root = buildTreeLevel();
    cout<<endl;
    printLevel(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // inorder(root);
    return 0;
}