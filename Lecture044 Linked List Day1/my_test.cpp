#include <iostream>
using namespace std;
#include "Node.cpp"

void insertAtStart(Node *&head)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        cin >> data;
    }
}

Node *insertAtStartWithNewHead(Node *head)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        cin >> data;
    }
    return head;
}

void insertAtEnd(Node *&tail)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
        cin >> data;
    }
}

void insertAtPostion(Node *&head)
{

    Node *temp = head;
    int pos, data;
    cin >> pos >> data;
    if (pos > 1)
    {
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
            return;
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else if (pos == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void deleteAtPostion(Node *&head)
{
    Node *temp = head;
    int pos, i = 1;
    cin >> pos;
    if (pos > 1)
    {
        while (i < pos - 1)
        {
            if (temp->next == NULL)
            {
                // cout << "ruk ja";
                return;
            }
            temp = temp->next;
            i++;
        }

        temp->next = temp->next->next;
    }
    else if (pos == 1)
    {
        head = temp->next;
    }
}
int main()
{

    // Node *n1 = new Node(10);
    // Node *head = n1;
    Node n1(10);
    Node *head = &n1;
    Node *tail = &n1;
    // insertAtStart(head);
    // print(head);

    // Node *head = insertAtStartWithNewHead(NULL);

    insertAtEnd(tail);
    print(head);
    // insertAtEnd(tail);
    // print(head);

    // insertAtPostion(head);
    // print(head);

    //** Deletion
    deleteAtPostion(head);
    print(head);
    return 0;
}