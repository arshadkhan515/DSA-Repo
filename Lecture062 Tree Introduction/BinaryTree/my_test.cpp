//?? Diameter of a Binary Tree
//** Approach 1

int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    int ans = 1;
    int l = height(node->left);
    int r = height(node->right);

    return max(l, r) + ans;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = diameter(root->left);
    int r = diameter(root->right);
    int both = height(root->left) + height(root->right) + 1;

    return max(l, max(r, both));
}

//** Approach 2
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> ans(0, 0);
        return ans;
    }

    pair<int, int> l = solve(root->left);
    pair<int, int> r = solve(root->right);
    int op1 = l.first;
    int op2 = r.first;
    int op3 = l.second + r.second + 1;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(l.second, r.second) + 1;
    return ans;
}

int diameter(Node *root)
{
    return solve(root).first;
}




// https://www.codingninjas.com/codestudio/problems/unival-trees_697311?leftPanelTab=0

//** Check for Balanced Tree
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<int,int> solve(Node* root){
        if(root == NULL)
        {
            pair<int,int> ans(true,0);
            return ans;
        }
        
        pair<bool,int> l = solve(root->left);
        pair<bool,int> r = solve(root->right);
        
        bool lA = l.first;
        bool rA = r.first;
        int diff = abs(l.second-r.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(l.second,r.second) + 1;
        
        if(lA && rA && diff){
            ans.first = true;
        }else{
            ans.first = false;
        }
        return ans;
        
    }
    bool isBalanced(Node *root)
    {
        return solve(root).first;
    }
};

//** https://practice.geeksforgeeks.org/problems/sum-tree/1
class Solution
{
    public:
    pair<bool,int> solve(Node* root){
        if(root == NULL)
        {
            pair<bool,int> ans(true,0);
            return ans;
        }
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> ans(true,root->data);
            return ans;
        }
        pair<bool,int> l = solve(root->left);
        pair<bool,int> r = solve(root->right);
        
        pair<bool,int> ans;
        if(l.first && r.first && (r.second+l.second == root->data)){
            ans.first = true;
        }else{
            ans.first = false;
        }
        ans.second = l.second+r.second+root->data;
        return ans;
    }
    bool isSumTree(Node* root)
    {
         return solve(root).first;
    }
};