//** Sort linked list of 0s 1s 2s
// void insertAtTail(Node* &tail,Node* curr){
//     tail->next = curr;
//     tail = curr;
// }
// Node* sortList(Node *head)
// {
//     Node* zeroHead = new Node(-1);
//     Node* zeroTail = zeroHead;
//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;
//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;
    
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp->data == 0){
//             insertAtTail(zeroTail,temp);
//         }else if(temp->data == 1){
//             insertAtTail(oneTail,temp);            
//         }else if(temp->data == 2){
//             insertAtTail(twoTail,temp);            
//         }
//         temp = temp->next;
//     }
    
//     if(oneHead->next != NULL){
//         zeroTail->next = oneHead->next;
//         oneTail->next = twoHead->next;
//         twoTail->next = NULL;
//     }else{
//         zeroTail->next = twoHead->next;
//         twoTail->next = NULL;
//     }
    
//     return zeroHead->next;
// }