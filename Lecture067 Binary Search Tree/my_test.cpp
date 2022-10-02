//** Print Elements in Range in BST   
// input: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// range: 6 10
// output: 6 7 8


// if the root value is greater than the range's start value then we will call the function for the left subtree.
// if the root value is in the range then we will print the root value and call the function for the left and right subtree.
// if the root value is less than the range's end value then we will call the function for the right subtree.


void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if(root == NULL)
        return;

    if(root->data > k1){
        elementsInRangeK1K2(root->left,k1,k2);
    }
    if(k1<=root->data && k2>=root->data){
        cout<<root->data<<" ";
    }

     if(root->data < k2){
        elementsInRangeK1K2(root->right,k1,k2);        
    }


}