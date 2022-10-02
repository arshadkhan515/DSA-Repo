// Largest BST in a Binary Tree 
// Approach of this problem is first create a custom class which will store the information of the tree like sixe of tree, minValueOfTree, maxValueOfTree, isBST;
// isBST value will be true if the left subtree and right subtree is BST and the root value is greater than the maxValue of left subtree and less than the minValue of right subtree.
// if the isBST value is true then we will update the maxBSTSize value with the size of the tree.
#include <bits/stdc++.h>
class custome{
    public:
    bool isBST;
    int maxi;
    int mini;
    int size;
};

custome solve(TreeNode<int>* root,int& maxSize){
  
    if(root == NULL){
        return {true,INT_MIN,INT_MAX,0};
    }
    custome l = solve(root->left,maxSize);
    custome r = solve(root->right,maxSize);
    
    custome ans;
    ans.size = l.size + r.size + 1;
    ans.maxi = max(r.maxi,root->data);
    ans.mini = min(l.mini,root->data);
    
    bool op1 = l.isBST;
    bool op2 = r.isBST;
    bool op3 = (l.maxi < root->data && r.mini > root->data);
    
    if(op1 && op2 && op3){
        ans.isBST = true;
    }else{
        ans.isBST = false;
    }
    if(ans.isBST && ans.size > maxSize){
        maxSize = ans.size;
    }
    return ans;
}


int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    custome ans =  solve(root,maxSize);
    return maxSize;
}
