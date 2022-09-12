
//** Approach 1
class Solution {
public:
    int findPosition(vector<int> inorder,int target){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preInd,int inorderStart,int inorderEnd,int n){
        
        if(preInd >= n || inorderStart > inorderEnd){
            return NULL;
        }
        
        int data = preorder[preInd++];
        TreeNode* root = new TreeNode(data);
        int position = findPosition(inorder,data);
        
        root->left = solve(preorder,inorder,preInd,inorderStart,position-1,n); 
        root->right = solve(preorder,inorder,preInd,position+1,inorderEnd,n);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preInd = 0;
        return solve(preorder,inorder,preInd,0,inorder.size()-1,preorder.size());
    }
};


//** Approach 2
class Solution {
public:
    void createMapping(vector<int> inorder,map<int,int> &Mapping){
        for(int i=0;i<inorder.size();i++){
                Mapping[inorder[i]] = i;
            }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preInd,int inorderStart,int inorderEnd,int n,map<int,int> &Mapping){
        
        if(preInd >= n || inorderStart > inorderEnd){
            return NULL;
        }
        
        int data = preorder[preInd++];
        TreeNode* root = new TreeNode(data);
        int position = Mapping[data];

        // In postOrder , we build first right subTree because in postOrder ,we traverse NLR order
        root->left = solve(preorder,inorder,preInd,inorderStart,position-1,n,Mapping); 
        root->right = solve(preorder,inorder,preInd,position+1,inorderEnd,n,Mapping);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preInd = 0;
        map<int,int> Mapping;
        createMapping(inorder,Mapping);
        return solve(preorder,inorder,preInd,0,inorder.size()-1,preorder.size(),Mapping);
    }
};






