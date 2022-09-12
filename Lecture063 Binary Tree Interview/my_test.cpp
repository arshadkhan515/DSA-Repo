//** level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
    	if(root == NULL)
    	return result;
    	q.push(root);
    	while(!q.empty()){
    	    
    	    int n = q.size();
    	    vector<int> ans(n);
    	    
    	    for(int i=0;i<n;i++){
    	        TreeNode* curr = q.front();
    	        q.pop();
    	        
    	        ans[i] = curr->val;
    	        
    	        if(curr->left != NULL){
    	            q.push(curr->left);
    	        }
    	        if(curr->right != NULL)
    	            q.push(curr->right);
    	            
    	    }
    	        result.push_back(ans);
    	    
    	}
        return result;
    }
};

// ** Sum of Left Leaves
class Solution {
public:
    bool isLeaf(TreeNode* root){
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int sum = 0;
        if(isLeaf(root->left)){
            sum += root->left->val;
        }
        
        int l = sumOfLeftLeaves(root->left);
        int r = sumOfLeftLeaves(root->right);
        return l+r+sum;

        
    }
};


