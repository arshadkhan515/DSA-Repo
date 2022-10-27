// https://www.geeksforgeeks.org/convert-bst-min-heap/
// https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=1
// Convert BST to Min Heap

// Approach of this problem is to convert BST to sorted array and then set the value in preorder fashion in the min heap.
// step 1: convert BST to sorted array.
// step 2: set the value in preorder fashion in the min heap tree.
// step 3: return the root of the min heap tree.

// because in BST is complete binary tree so we can convert it to sorted array in O(n) time.

#include <bits/stdc++.h> 

void makeArray(vector<int>&inorderArr,BinaryTreeNode* root){
    if(root == NULL)
        return;

    makeArray(inorderArr,root->left);
    inorderArr.push_back(root->data);
    makeArray(inorderArr,root->right);
}

void ConvertBSTtoMinHeap(BinaryTreeNode* root,vector<int>&in,int& ind){
    if(root == NULL)
        return;

    if(ind>=in.size()){
        return;
    }
    root->data = in[ind++];
    ConvertBSTtoMinHeap(root->left,in,ind);
    ConvertBSTtoMinHeap(root->right,in,ind);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> inorderArr;
    makeArray(inorderArr,root);
    int i = 0;

    ConvertBSTtoMinHeap(root,inorderArr,i);
    return root;
}