//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //if one value is present for a HD, then do nothing
            if(topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode -> data;
                
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode) 
        {
            ans.push_back(i.second);
        }
        return ans;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends