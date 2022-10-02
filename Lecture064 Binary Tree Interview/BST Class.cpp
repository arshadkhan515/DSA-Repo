#include<bits/stdc++.h>
class BST {
    BinaryTreeNode<int>* insertAtBST(BinaryTreeNode<int>* root,int data){
        if(root == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data <= root->data){
            root->left = insertAtBST(root->left,data);
        }else{
            root->right = insertAtBST(root->right,data);
        }
        return root; 
    }
    bool searchInBST(BinaryTreeNode<int>* root,int data){
        if(root == NULL)
            return false;
        if(root->data == data){
            return true;
        }

        if(data < root->data)
            return searchInBST(root->left,data);
        else
            return searchInBST(root->right,data);
    }
    void printBST(BinaryTreeNode<int>* root){
        if(root == NULL)
            return;

        cout<<root->data<<":";
        if(root->left != NULL)
            cout<<"L:"<<root->left->data<<",";

        if(root->right != NULL)
            cout<<"R:"<<root->right->data;

        cout<<endl;

        printBST(root->left);
        printBST(root->right);

    }
    int findMini(BinaryTreeNode<int>* root){
        if(root == NULL)
            return INT_MAX;
        
        return min(root->data,min(findMini(root->left),findMini(root->right)));
        // BinaryTreeNode<int>* ptr = root;
        // while(ptr->left != NULL){
        //     ptr = ptr->left;
        // }
        // return ptr->data;

    }
    BinaryTreeNode<int>* removeAtBST(BinaryTreeNode<int>* root,int data){
        if(root == NULL)
            return NULL;

        if(root->data == data){
            // leaf Node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            if(root->left != NULL && root->right == NULL){
                BinaryTreeNode<int>* temp = root;
                delete root;
                return temp->left;
            }

            if(root->left == NULL && root->right != NULL){
                BinaryTreeNode<int>* temp = root;
                delete root;
                return temp->right;
            }
            if(root->left != NULL && root->right != NULL){
                BinaryTreeNode<int>* temp = root;
                int getMini = findMini(root->right);
                root->data = getMini;
                root->right = removeAtBST(root->right,getMini);
                return root;
            }

        }

        if(data < root->data)
            root->left = removeAtBST(root->left,data);
        else
            root->right = removeAtBST(root->right,data);

        return root;
    }

    public:
    BinaryTreeNode<int>*root;
    BST() { 
        root = NULL;
    }
    /*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        root = removeAtBST(root,data);
    }

    void print() { 
        printBST(root);
    }

    void insert(int data) { 
        root = insertAtBST(root,data);
    }

    bool search(int data) {
        return searchInBST(root,data);
    }
};