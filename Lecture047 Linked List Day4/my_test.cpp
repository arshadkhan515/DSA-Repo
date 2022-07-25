
// ** Find the LinkList have loop or Not
// Node * floydAlgo(Node* head){
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     Node * slow = head;
//     Node* fast = head;

//     while(slow != NULL && fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;

//         if(slow == fast){
//             return slow;
//         }
//     }
//     return NULL;

// }
// ** Find the Loop's Starting Point
// Node * loopStart(Node * head){

//     Node * inter = floydDetectLoop(head);
//     if(inter != NULL){
//         Node * slow = head;

//       while(slow != NULL && inter != NULL){
//         slow = slow->next;
//         inter = inter->next;

//         if(slow == inter){
//             return slow;
//         }
//       }
//     }
//     return NULL;
// }


