#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node *&tail, int ele, int data)
{
    Node *newNode = new Node(data);
    if (tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != ele)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void deleteNode(Node *&tail, int ele)
{

    Node *pre = tail;
    Node *curr = pre->next;
    while (curr->data != ele)
    {
        pre = curr;
        curr = curr->next;
    }
    if (pre == curr)
    {
        tail = NULL;
    }
    else
    {
        pre->next = curr->next;
        if (tail == curr)
        {
            tail = pre;
        }
        delete curr;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 3, 10);
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 10, 40);
    print(tail);
    deleteNode(tail, 10);
    deleteNode(tail, 30);
    deleteNode(tail, 20);
    deleteNode(tail, 40);
    print(tail);
    return 0;
}