// Two sum problem using BST 
// Approach, make sorted array using inorder traversal of BST and then use two pointer approach
// And then find the pair of numbers which sum up to the target value 
// Time Complexity: O(n)
// Space Complexity: O(n)



#include <bits/stdc++.h>
void makeArray(vector<int>& inorderArr,BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    
    makeArray(inorderArr,root->left);
    inorderArr.push_back(root->data);
    makeArray(inorderArr,root->right);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorderArr;
    makeArray(inorderArr,root);
    int i=0,j=inorderArr.size()-1;
    
    while(i<j){
        int SumOfboth = inorderArr[i]+inorderArr[j];
        if(SumOfboth == target){
            return true;
        }else if(SumOfboth > target){
            j--;
        }else{
            i++;
        }
        
    }
    return false;
}





