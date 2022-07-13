#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *pre;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
    // ~Node()
    // {
    //     int value = this->data;
    //     if (this->next != NULL)
    //     {
    //         delete next;
    //         this->next = NULL;
    //         this->pre = NULL;
    //     }
    //     cout << "Free Memory " << value << endl;
    // }
};

Node *insertAtStart(Node *head)
{
    int data;
    cin >> data;
    Node *newNode = new Node(data);

    while (data != -1)
    {
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
        cin >> data;
    }

    return head;
}

Node *insertAtEnd(Node *head)
{
    Node *tail = head;
    int data;

    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->pre = tail;
        tail = newNode;
        cin >> data;
    }
    return tail;
}

Node *deleteAtPostion(Node *head)
{
    Node *curr = head;
    Node *pre = NULL;
    int pos, i = 1;
    cin >> pos;
    if (pos > 1)
    {
        while (i < pos)
        {
            if (curr->next == NULL)
            {
                break;
            }
            pre = curr;
            curr = curr->next;
            i++;
        }
        pre->next = curr->next;
        if (curr->next != NULL)
        {
            curr->next->pre = pre;
        }
        delete curr;
    }
    else if (pos == 1)
    {
        head = curr->next;
        head->pre = NULL;
    }
    return head;
}

void printA(Node *head)
{
    Node *temp = head;

    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->pre;
    }
    cout << endl;
}
void printR(Node *tail)
{
    Node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->pre;
    }
    cout << endl;
}

int main()
{
    Node n1(10);
    Node *head = &n1;
    Node *tail = &n1;

    // head = insertAtStart(head);
    // printA(head);
    tail = insertAtEnd(tail);
    printA(head);
    // tail = insertAtEnd(tail);
    // printA(head);
    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;

    head = deleteAtPostion(head);
    cout << "Head " << head->data << endl;
    printA(head);
    // printR(tail);

    return 0;
}