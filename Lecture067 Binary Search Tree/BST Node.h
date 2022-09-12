#include<bits/stdc++.h>
using namespace std;

class BNode
{
public:
    int data;
    BNode *left;
    BNode *right;

    BNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};