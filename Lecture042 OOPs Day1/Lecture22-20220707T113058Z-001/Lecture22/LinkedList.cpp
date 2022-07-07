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
int main() {
    // 10->20->30->40
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;


    Node* head = &n1;
    print(head);
    // print(head);

    // Dynamically Node
    Node* node = new Node(50);
    cout << node->data << " ";
    cout << node->next << "\n";

    delete node;
}