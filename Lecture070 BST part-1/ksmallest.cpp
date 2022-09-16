//* kth Smaller Element in BST is the kth element in the inorder traversal of the BST (inorder traversal of BST gives the elements in sorted order) 
//? brute force of approach is to do inorder traversal and store the elements in an array and then return the kth element of the array
// 1. Do inorder traversal of BST and store the elements in an array
// 2. Return the kth element of the array
// Time Complexity: O(n)
// Space Complexity: O(n)








//** this is the recursive solution for kth smallest element in BST using inorder traversal of BST 
// Time Complexity: O(n)
// Space Complexity: O(n)
int solve(BinaryTreeNode<int>* root, int k,int&i){
    if(root == NULL)
        return -1;
    
    int l = solve(root->left,k,i);
    if(l != -1)
        return l;
    i++;
    if(k==i)
        return root->data;
    return solve(root->right,k,i);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    return solve(root,k,i);
}