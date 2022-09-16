#include<bits/stdc++.h>
using namespace std;


//* Validate BST is a function that checks if a given binary tree is a BST or not 
//? brute force approach is to do inorder traversal of the tree and store the elements in an array and then check if the array is sorted or not
//* becuase inorder traversal of BST gives the elements in sorted order
// 1. Do inorder traversal of the tree and store the elements in an array
// 2. Check if the array is sorted or not
// Time Complexity: O(n)
// Space Complexity: O(n)


void solve(BinaryTreeNode<int>* root,vector<int>& ans){
    if(root == NULL)
        return;
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}
bool validateBST(BinaryTreeNode<int> *root) {
    vector<int> ans;
    solve(root,ans);
    return is_sorted(ans.begin(),ans.end());
}


// **This is the recursive solution for validate BST 
// to check range of each node in the tree 
// 1. if the root is NULL then return true
// 2. if the root->data is less than min or greater than max then return false otherwise return true
// 3. return validateBST(root->left,min,root->data) && validateBST(root->right,root->data,max)
// Time Complexity: O(n)
// Space Complexity: O(n)
bool solve(BinaryTreeNode<int>* root,int min,int max){
        if(root == NULL)
            return true;
        
        if(root->data >= min && root->data <= max){
            bool l = solve(root->left,min,root->data);  
            bool r = solve(root->right,root->data,max);

            return l && r;
        }else
            return false;

    }
bool validateBST(BinaryTreeNode<int> *root) {
   return solve(root,INT_MIN,INT_MAX);
}