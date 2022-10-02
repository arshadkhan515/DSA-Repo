//Merge Two BST
// merge two BST and return the new BST
// Approach 1
// 1. Do inorder traversal of both the trees and store the elements in two different arrays
// 2. merge the two arrays using merge two sorted arrays function and store the elements in a new array 
// 3. build a new tree using the sorted array and return the root of the new tree
// Time Complexity: O(n+m)
// Space Complexity: O(n+m)


#include <bits/stdc++.h>
void inorderArr(TreeNode<int> *root1,vector<int>& ans){
    if(root1 == NULL)
        return;

    inorderArr(root1->left,ans);
    ans.push_back(root1->data);
    inorderArr(root1->right,ans);
}
vector<int> margeSortedArray(vector<int>& T1,vector<int>& T2){
    int n = T1.size();
    int m = T2.size();
    vector<int> ans(n+m);

    int i = 0,j = 0;
     int k = 0;
    while(i<n && j<m){
        if(T1[i] < T2[j]){
            ans[k++] = T1[i++];
        }else{
            ans[k++] = T2[j++];
        }
    }

    while(i<n){
        ans[k++] = T1[i++];
    }
    while(j<m){
        ans[k++] = T2[j++];
    }

    return ans;
}
TreeNode<int>* buildNewTreeUsingInorder(vector<int>& arr,int s,int e){
    if(s>e)
        return NULL;
    
    
    int mid = s+(e-s)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = buildNewTreeUsingInorder(arr,s,mid-1);
    root->right = buildNewTreeUsingInorder(arr,mid+1,e);
    
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // step 1 make inorder traversal of both the trees and store the elements in two different arrays
    vector<int> T1;        
    vector<int> T2;
    inorderArr(root1,T1);
    inorderArr(root2,T2);
// step 2 merge the two arrays using merge two sorted arrays function and store the elements in a new array
    vector<int> margeArr = margeSortedArray(T1,T2);
// step 3 build a new tree using the sorted array and return the root of the new tree
    return buildNewTreeUsingInorder(margeArr,0,margeArr.size()-1);
}