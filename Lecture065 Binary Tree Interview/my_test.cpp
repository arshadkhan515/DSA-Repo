//** Sum of Longest BloodLine
class Solution
{
public:
  void solve(Node *root, int len, int &MaxLen, int sum, int &MaxSum)
  {
    if (root == NULL)
    {
      if (len > MaxLen)
      {
        MaxLen = len;
        MaxSum = sum;
      }
      else if (len == MaxLen)
      {
        MaxSum = sum;
      }
      return;
    }

    sum += root->data;

    solve(root->left, len + 1, MaxLen, sum, MaxSum);
    solve(root->right, len + 1, MaxLen, sum, MaxSum);
  }

  int sumOfLongRootToLeafPath(Node *root)
  {
    int MaxLen = 0;
    int len = 0;
    int MaxSum = 0;
    int sum = 0;
    solve(root, len, MaxLen, sum, MaxSum);
    return MaxSum;
  }
};

//** Lowest Common Ancestor of a Binary Tree
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2)
  {

    if (root == NULL || root == n1 || root == n2)
      return root;

    auto l = lowestCommonAncestor(root->left, n1, n2);
    auto r = lowestCommonAncestor(root->right, n1, n2);

    if (l == NULL)
      return r;
    else if (r == NULL)
      return l;
    else
      return root;
  }
};

//** 437. Path Sum III

class Solution
{
public:
  void solve(TreeNode *root, int &count, vector<int> path, int k)
  {
    if (root == NULL)
      return;

    path.push_back(root->val);

    solve(root->left, count, path, k);
    solve(root->right, count, path, k);

    long long sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
      sum += path[i];
      if (sum == k)
      {
        count++;
      }
    }
    path.pop_back();
  }
  int pathSum(TreeNode *root, int k)
  {
    int count = 0;
    vector<int> path;
    solve(root, count, path, k);
    return count;
  }
};

//** 112. Path Sum

class Solution
{
public:
  void solve(TreeNode *root, bool &ans, vector<int> path, int k)
  {
    if (root == NULL)
      return;

    path.push_back(root->val);

    if (root->left == NULL && root->right == NULL)
    {
      long long sum = 0;
      for (auto i : path)
      {
        sum += i;
      }

      if (sum == k)
      {
        ans = true;
      }
    }
    solve(root->left, ans, path, k);
    solve(root->right, ans, path, k);
  }
  bool hasPathSum(TreeNode *root, int k)
  {
    bool ans = false;
    vector<int> path;
    solve(root, ans, path, k);
    return ans;
  }
};

//** 113. Path Sum II

class Solution
{
public:
  void solve(TreeNode *root, vector<vector<int>> &ans, vector<int> path, int k)
  {
    if (root == NULL)
      return;

    path.push_back(root->val);

    if (root->left == NULL && root->right == NULL)
    {
      int sum = 0;
      for (auto i : path)
      {
        sum += i;
      }
      if (k == sum)
      {
        ans.push_back(path);
      }
    }

    solve(root->left, ans, path, k);
    solve(root->right, ans, path, k);
  }
  vector<vector<int>> pathSum(TreeNode *root, int k)
  {
    vector<vector<int>> ans;
    vector<int> path;
    solve(root, ans, path, k);
    return ans;
  }
};


//** Kth Ancestor in a Tree
void solve(Node *root, int &ans, vector<int> path, int k, int node)
{
  if (root == NULL)
    return;

  path.push_back(root->data);

  if (root->data == node)
  {
    int temp = 1;
    for (int i = path.size() - 1; i >= 0; i--)
    {
      if (k == 0)
      {
        ans = path[i];
      }
      k--;
    }
  }

  solve(root->left, ans, path, k, node);
  solve(root->right, ans, path, k, node);
}
int kthAncestor(Node *root, int k, int node)
{
  int ans = -1;
  vector<int> path;
  solve(root, ans, path, k, node);
  return ans;
}