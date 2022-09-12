//** Boundary Traversal of binary tree

class Solution
{
public:
    void leftBoundary(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        ans.push_back(root->data);

        if (root->left != NULL)
            leftBoundary(root->left, ans);
        else
            leftBoundary(root->right, ans);
    }
    void leafNodes(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }
    void reverseRightNodes(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        if (root->right != NULL)
            reverseRightNodes(root->right, ans);
        else
            reverseRightNodes(root->left, ans);

        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        ans.push_back(root->data);
        leftBoundary(root->left, ans);

        leafNodes(root->left, ans);
        leafNodes(root->right, ans);

        reverseRightNodes(root->right, ans);
        return ans;
    }
};

//** ZigZag Traversal
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        if (root == NULL)
            return result;
        q.push(root);
        int flag = true;
        while (!q.empty())
        {

            int n = q.size();
            vector<int> ans(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                int index = flag ? i : n - i - 1;
                ans[index] = curr->val;

                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            flag = !flag;
            result.push_back(ans);
        }
        return result;
    }
};

//** Top View of Binary Tree
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<pair<Node *, int>> q;
        map<int, int> M;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            auto node = curr.first;
            auto hd = curr.second;

            if (M.find(hd) == M.end())
            {
                M[hd] = node->data;
            }

            if (node->left != NULL)
            {
                q.push(make_pair(node->left, hd - 1));
            }
            if (node->right != NULL)
            {
                q.push(make_pair(node->right, hd + 1));
            }
        }
        for (auto i : M)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

//** Bottom View of Binary Tree
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {

        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> M;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            auto node = curr.first;
            auto hd = curr.second;

            M[hd] = node->data;

            if (node->left != NULL)
                q.push(make_pair(node->left, hd - 1));
            if (node->right != NULL)
                q.push(make_pair(node->right, hd + 1));
        }
        for (auto i : M)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};



//** 199. Binary Tree Right Side View
//?? Approach 1
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                auto node = q.front();
                q.pop();
                if (i == n)
                {
                    ans.push_back(node->val);
                }

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
//?? Approach 2
class Solution
{
    public:
    void solve(Node* root,vector<int>& ans,int level){
    if(root == NULL)
        return;
        
    if(level == ans.size())
        ans.push_back(root->data);
    
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
              vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};




//** Left View of Binary Tree
//?? Approach 1
vector<int> leftView(Node *root)
{
    // 1
    // vector<int> ans;
    // solve(root,ans,0);
    // return ans;
    // 2
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            auto node = q.front();
            q.pop();
            if (i == 1)
            {
                ans.push_back(node->data);
            }

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }
    return ans;
}
// ?? Approach 2
void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
