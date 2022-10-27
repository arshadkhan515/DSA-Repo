//** Print Elements in Range in BST   
// input: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// range: 6 10
// output: 6 7 8
// https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1

// if the root value is greater than the range's start value then we will call the function for the left subtree.
// if the root value is in the range then we will print the root value and call the function for the left and right subtree.
// if the root value is less than the range's end value then we will call the function for the right subtree.


void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if(root == NULL)
        return;

    if(root->data > k1){
        elementsInRangeK1K2(root->left,k1,k2);
    }
    if(k1<=root->data && k2>=root->data){
        cout<<root->data<<" ";
    }

     if(root->data < k2){
        elementsInRangeK1K2(root->right,k1,k2);        
    }
}

class Solution {
  public:
    void solve(Node* root,int i,int j,vector<int>& ans){
        if(root == NULL)
        return;
        
        if(root->data > i){
            solve(root->left,i,j,ans);
        }
        
        if(i<=root->data && j >= root->data){
            ans.push_back(root->data);
        }
        if(root->data < j){
            solve(root->right,i,j,ans);
        }
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        solve(root,low,high,ans);
        return ans;
    }
};


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return 0;
        
        int sum = 0;
        if(root->val > low)
        {
             sum += rangeSumBST(root->left,low,high);
        }
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
        
        if(root->val < high){
            sum += rangeSumBST(root->right,low,high);
        }
        
        return sum;
    }
};