// LCA in BST 
// Recursive solution 
// step 1: if both keys are smaller than root, then LCA lies in left
// step 2: if both keys are greater than root, then LCA lies in right
// step 3: if both keys are not smaller and not greater, then root is LCA because,this root is first node where keys are on different sides
// https://www.youtube.com/watch?v=cX_kPV_foZc (video)
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left,P,Q);
    }
    if(root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    return root;
}