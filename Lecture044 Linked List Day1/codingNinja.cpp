#include<iostream>
using namespace std;

#include "Node.cpp"

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* takeInput() {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    cin >> data;
    while(data != -1) {
        // Insert LL
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Node* temp = head;
            // while(temp->next != NULL) {
            //     temp = temp->next;
            // }
            tail->next = newNode;
            tail = newNode;
            // OR tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
Node* insertNodeatIth(int data, int i, Node* head) {
    if(i == 0) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    // (i - 1)th node
    Node* temp = head;
    int currPos = 0;
    while(temp != NULL && currPos < i - 1) {
        temp = temp->next;
        currPos += 1;
    }
    if(temp != NULL) {
        Node* newNode = new Node(data);

        // Approach 1
        newNode->next = temp->next;
        temp->next = newNode;

        // Approach 2
        // Node* a = temp->next;
        // temp->next = newNode;
        // newNode->next = a;
    }
    return head;
}
int main() {
    Node* head = takeInput();
    print(head);
    head = insertNodeatIth(1000, 0, head);
    print(head);
}