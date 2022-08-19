#include <bits/stdc++.h>
using namespace std;
#include "LinkedList.cpp"

class Stack
{
public:
    int top;
    int size;
    int *newArray;
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        newArray = new int[size];
    }
    void push(int data)
    {
        top++;
        if (this->top < this->size)
            newArray[top] = data;
        else
            cout << "Stack is OverFlow" << endl;
    }
    void peek()
    {
        if (!this->empty())
            cout << newArray[top] << endl;
        else
            cout << "Stack is Empty" << endl;
    }
    void pop()
    {
        if (this->empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            top--;
        }
    }
    bool empty()
    {
        if (top < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class StackLinkList
{
public:
    int sizeStack;
    Node *head;
    StackLinkList()
    {
        this->head = NULL;
        this->sizeStack = 0;
    }
    void push(int data)
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
        sizeStack++;
    }
    void peek()
    {
        if (!this->empty())
            cout << head->data << endl;
        else
            cout << "Stack is Empty" << endl;
    }
    void pop()
    {
        if (this->empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        sizeStack--;
    }
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        return sizeStack;
    }
};
// ?Stack using Queue 
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main()
{

    // StackLinkList *newStack = new StackLinkList();
    // // cout<<newStack->empty();
    // newStack->push(10);
    // newStack->push(20);
    // newStack->push(30);
    // // newStack->push(40);
    // // cout<<newStack->empty();
    // cout << newStack->size()<<endl;
    // newStack->peek();
    // newStack->pop();
    // newStack->peek();
    // newStack->pop();
    // cout << newStack->size()<<endl;
    // newStack->peek();
    // newStack->pop();
    // // cout<<newStack->empty();
    // newStack->peek();

    //? Stack using Array
    Stack *newStack = new Stack(5);
    newStack->push(10);
    newStack->push(20);
    newStack->push(30);

    newStack->peek();
    newStack->pop();
    newStack->peek();
    newStack->pop();
    newStack->peek();
    newStack->pop();
    newStack->peek();
    newStack->pop();
    newStack->push(10);
    newStack->peek();
    newStack->pop();

    return 0;
}