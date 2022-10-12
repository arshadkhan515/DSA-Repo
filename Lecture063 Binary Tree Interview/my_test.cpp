// problem of custom class approach is we use a lot of time.
// step of the approach is to create a custom class and then use it.
// we can use a lot of time in this approach.


/* first we create a custom class and then we use it.
   base case
   calls
   perform operation for the answer
   and fill the custom class with the answer.
*/



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

//** BST to Sorted LL using class
class Base{
    public:
    Node<int>* head;
    Node<int>* tail;

    Base(){
        head = NULL;
        tail = NULL;
    }
};
Base solve(BinaryTreeNode<int>* root){
    Base ans;

    if(root == NULL){
        return ans;
    }
    
    Base l = solve(root->left);
    Base r = solve(root->right);
    Node<int>* newNode = new Node<int>(root->data);

    if(l.tail != NULL){
        l.tail->next = newNode;
    }
    newNode->next = r.head;
    
    if(l.head != NULL){
        ans.head = l.head;
    }else{
        ans.head = newNode;
    }
    
    if(r.tail != NULL){
        ans.tail = r.tail;
    }else{
        ans.tail = newNode;
    }
    
    return ans;

}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {

    return solve(root).head;

}
// ** BST to Sorted LL using Recursion
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	
    if(root == NULL){
        return NULL;
    }
    
    Node<int> * l = constructLinkedList(root->left);
    Node<int> * r = constructLinkedList(root->right);
    
    
    Node<int> * head = new Node<int>(root->data);
    if(l == NULL){
        head->next = r;
        return head;
    }else{
        Node<int>* temp = l;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        head->next = r;
        return l;
    }
    
}

// merge two Binary Tree using recursion
// leetcode 617
class Solution {
public:
    TreeNode* solve(TreeNode* root1, TreeNode* root2){
           
        TreeNode* root = NULL;
        
        if(root1 == NULL && root2 == NULL)
        {
            return NULL;
        }
        
        if(root1 != NULL && root2 != NULL)
        {
            root = new TreeNode(root1->val + root2->val);
        }
        
        if(root1 != NULL && root2 == NULL)
        {
            return root1;
        }else if(root1 == NULL && root2 != NULL)
        {
            return root2;
        }
        
        root->left = solve(root1->left,root2->left);
        root->right = solve(root1->right,root2->right);
        
        return root;
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {   
        return solve(root1,root2);
    }
};

