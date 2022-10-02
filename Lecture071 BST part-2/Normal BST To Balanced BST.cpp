// Normal BST To Balanced BST 
// Approach, make sorted array using inorder traversal of BST and then make a balanced BST from the array
// And start of making the balanced BST using recursion 

//** find the mid of the array and make it the root of the BST and then make the left subtree of the root and the right subtree of the root becuase the array is sorted mid left part of the array will be the left subtree and the right part of the array will be the right subtree 
 
// Time Complexity: O(n)
// Space Complexity: O(n)


#include <bits/stdc++.h>
void makeArray(vector<int>& inorderArr,TreeNode<int>* root){
    if(root == NULL)
        return;
    
    makeArray(inorderArr,root->left);
    inorderArr.push_back(root->data);
    makeArray(inorderArr,root->right);
}

TreeNode<int>* buildBalance(vector<int>& inorderArr,int s,int e){
    if(inorderArr.size() == 0)
        return NULL;
    
    if(s>e){
        return NULL;
    }
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inorderArr[mid]);
    
    TreeNode<int>* l = buildBalance(inorderArr,s,mid-1);
    TreeNode<int>* r = buildBalance(inorderArr,mid+1,e);
    
    root->left = l;
    root->right = r;
    return root;
    
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderArr;
    makeArray(inorderArr,root);
    int n=inorderArr.size();
   
    return buildBalance(inorderArr,0,n-1);
}



