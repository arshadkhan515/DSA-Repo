/* 
 *inorder predecessor and successor is the node which is just smaller and larger than the given node
 *inorder predecessor is the node which is just smaller than the given node
 *inorder successor is the node which is just larger than the given node*/

// ?first approach is to do inorder traversal of the tree and store the elements in an array and then find the index of the given node and then return the predecessor and successor

// this is brute force approach and it takes O(n) time and O(n) space
// code snippet for this approach is given below


void solve(BinaryTreeNode<int>* root,int x,vector<int>& ans){
    if(root == NULL)
        return;
    solve(root->left,x,ans);
    ans.push_back(root->data);
    solve(root->right,x,ans);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int x)
{
    vector <int> ans;
    pair<int,int> PS;
    solve(root,x,ans);
    PS.first = -1;
    PS.second = -1;
    for(int i=0;i<ans.size();i++){
        if(ans[i] == x){
            if(i-1 >= 0)
                PS.first= ans[i-1];
            if(i+1 < ans.size())
                PS.second= ans[i+1];
        }
    }
    return PS;
}

//Approach 2 itrative approach
// this approach takes O(n) time and O(1) space
// code snippet for this approach is given below

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int x)
{
    pair<int,int> PS;
    BinaryTreeNode<int>* ptr = root;
    int succ = -1;
    int prec = -1;

    
    // first we will find the node with value x
    // with this we will find the successor and predecessor of the node
    // if node data is greater than x then it means that the node can be the successor of the node
    // if node data is smaller than x then it means that the node can be the predecessor of the node
    while(ptr->data != x){
      if(ptr->data > x){
          succ = ptr->data;
          ptr = ptr->left;
      }
      else{
          prec = ptr->data;
          ptr = ptr->right;
      }
    }


    // here we have found the node with value x and now we will find the successor and predecessor of the node
    // if the node has left subtree then the maximum element of the left subtree will be the predecessor
    BinaryTreeNode<int>* leftTree = ptr->left;
    while(leftTree != NULL){
        prec = leftTree->data;
        leftTree = leftTree->right;
    }

    // if the node has right subtree then the minimum element of the right subtree will be the successor
    BinaryTreeNode<int>* RightTree = ptr->right;
    while(RightTree != NULL){
        succ = RightTree->data;
        RightTree = RightTree->left;
    }


    PS.first = prec;
    PS.second = succ;
    return PS;
}



