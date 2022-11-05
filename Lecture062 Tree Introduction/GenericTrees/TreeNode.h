#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
        // first delete root node then delete its children nodes.
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
