// Build Tree using preorder
// Given Preorder traversal of a binary search tree, construct the BST.


// Approach of this problem is to use range of each node in the tree
// 1. if the root is NULL then return NULL
// 2. if the root->data is less than min or greater than max then return NULL otherwise make a new node with pre[preIndex] and increment preIndex by 1 and make root->left = solve(root->left,min,root->data) and root->right = solve(root->right,root->data,max) and return root
// Time Complexity: O(n)
// Space Complexity: O(n) of the stack
#include <bits/stdc++.h> 
BinaryTreeNode<int>* solve(vector<int> &preorder,int mini,int maxi,int& i){
    if(i>=preorder.size())
        return NULL;
    
    if(preorder[i]<=maxi && preorder[i]>=mini){
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
        root->left = solve(preorder,mini,root->data,i);
        root->right = solve(preorder,root->data,maxi,i);
        
        return root;
    }else
        return NULL;
    
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int minV = INT_MIN;
    int maxV = INT_MAX;
    int i = 0;
    return solve(preorder,minV,maxV,i);
}

// Approach 2
// time complexity: O(n^2)
// space complexity: O(n)
BinaryTreeNode<int>* solve(vector<int> &preorder,int start,int end){
    if(start > end)
        return NULL;
    
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[start]);

        int i;
        for(i=start+1;i<=end;i++){
            if(preorder[i] > preorder[start])
                break;
        }
        root->left = solve(preorder,start+1,i-1);
        root->right = solve(preorder,i,end);
        
        return root;
    
    
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int start = 0;
    int end = preorder.size()-1;
    return solve(preorder,start,end);
}

