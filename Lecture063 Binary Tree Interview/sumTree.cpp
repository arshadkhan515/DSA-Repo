// sumTree is a binary tree where each root node value is equal to the sum of its left and right child node values.
// brute force - O(n^2)
// And Optimized Solution - O(n)
// in this solution we will use pair class to store the sum and boolean value in the recursive function
// 1. we will check if the left and right tree are sum tree or not
// 2. if both are sum tree then we will check if the root node value is equal to the sum of left and right child node values
// 3. if all the above conditions are true then we will return sum of tree and current node value as true
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root) {
        
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        
        if(isLeftSumTree && isRightSumTree && condn) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum ;
        }
        else
        {
            ans.first = false;
        }
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};