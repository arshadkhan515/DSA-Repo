#include<iostream>
#include<unordered_map>
using namespace std;


//** Split a Circular Linked List into two halves
// void splitList(Node *head, Node **head1_ref, Node **head2_ref)
// {
//     Node * slow = head;
//     Node * fast = head->next;
//     Node * store = NULL;
    
//     while(fast != head && fast->next != head){
//         slow = slow ->next;
//         if(fast->next->next == head){
//             store = fast->next;
//         }
//         fast = fast->next->next;
//     }
    
//     if(fast->next == head){
//         store = fast;
//     }
    
//     *head1_ref = head;
//     Node * temp = slow->next;
//     slow->next = head;
    
//     *head2_ref = temp;
//     store->next = temp;
// }



// **Remove Duplicates From an Unsorted Linked List
//? Approach 1
// Node *removeDuplicatesFromUnsorted(Node *head)
// {
//     unordered_map<int, bool> visited;
//     Node * temp = head;
//     Node * pre = NULL;
//     while(temp != NULL){
//         if(visited[temp->data] == true){
//             pre->next = temp->next;
//             delete temp;
//             temp = temp->next;
//         }else{
//             visited[temp->data] = true;
//             pre = temp;
//             temp = temp->next;
//         }
//     }
//     return head;
// }
//? Approach 2
// Node *removeDuplicates(Node *head)
// {
//     Node * temp = head;
//     while(temp != NULL){
//         Node * pre = temp;
//         Node* temp2 = temp->next;
//         while(temp2 != NULL){
//             if(temp->data == temp2->data){
//                 pre->next = temp2->next;
//                 temp2 = temp2->next;
//             }else{
//                 pre = temp2;
//                 temp2 = temp2->next;
//             }
//         }
//         temp = temp->next;
//     }
//     return head;
// }


// **Remove Duplicates From Sorted List
// Node * uniqueSortedList(Node * head) {
//     Node * curr = head;
//     while(curr != NULL && curr->next != NULL){
//           if(curr->data == curr->next->data){
//               Node * temp = curr->next;
//               curr->next = curr->next->next;
//               delete temp;
//           }else{
//               curr = curr->next;
//           }
//     }
//     return head;
// }