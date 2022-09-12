class Solution {
public:
    void createMapping(vector<int> inorder,map<int,int> &Mapping){
        for(int i=0;i<inorder.size();i++){
                Mapping[inorder[i]] = i;
            }
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int &postInd,int inorderStart,int inorderEnd,map<int,int> &Mapping){
        
        if(postInd < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        // create root node
        int data = postorder[postInd--];
        TreeNode* root = new TreeNode(data);

        // find the position in mapping 
        int position = Mapping[data];
        
        // In postOrder , we build first right subTree because in postOrder ,we traverse NRL order
        root->right = solve(postorder,inorder,postInd,position+1,inorderEnd,Mapping);
        root->left = solve(postorder,inorder,postInd,inorderStart,position-1,Mapping); 
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postInd = postorder.size()-1;
        map<int,int> Mapping;
        createMapping(inorder,Mapping);
        return solve(postorder,inorder,postInd,0,inorder.size()-1,Mapping);
    }
};