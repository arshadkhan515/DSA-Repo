#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BNode
{
public:
    T data;
    BNode<T> *left;
    BNode<T> *right;

    BNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BNode()
    {
        delete left;
        delete right;
    }
};