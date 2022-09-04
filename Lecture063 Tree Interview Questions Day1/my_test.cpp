class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
              vector<vector<int>> result;
    	queue<TreeNode*> q;
    	if(root == NULL)
    	return result;
    	q.push(root);
    	int flag = true;
    	while(!q.empty()){
    	    
    	    int n = q.size();
    	    vector<int> ans(n);
    	    
    	    for(int i=0;i<n;i++){
    	        TreeNode* curr = q.front();
    	        q.pop();
    	        
    	        int index = flag ? i : n-i-1;
    	        ans[index] = curr->val;
    	        
    	        
    	        if(curr->left != NULL){
    	            q.push(curr->left);
    	        }
    	        if(curr->right != NULL)
    	            q.push(curr->right);
    	            
    	    }
    	    flag = !flag;
    	        result.push_back(ans);
    	    
    	}
    	return result;
    }
};

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