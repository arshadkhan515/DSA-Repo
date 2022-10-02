// Flatten BST To A Sorted List 
// Approach, make sorted array using inorder traversal of BST and then make a linked list from the array


/* 
 first take head node and then start making the linked list from the array,
 using loop make the curr pointer point to the next node of the linked list and then make the left pointer of the root point to NULL and the right pointer of the root point to the newNode which is the next node of the linked list
 */


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
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderArr;
    makeArray(inorderArr,root);
    int n=inorderArr.size();
    TreeNode<int>* head =  new TreeNode<int>(inorderArr[0]);
    TreeNode<int>* curr = head;
    
    for(int i = 1 ;i<n;i++){
        TreeNode<int>* newNode = new TreeNode<int>(inorderArr[i]);
//         curr->left = NULL;
        curr->right = newNode; 
        curr = newNode;
    }
//     curr->left = NULL;
    curr->right = NULL;
    
    return head;
}
