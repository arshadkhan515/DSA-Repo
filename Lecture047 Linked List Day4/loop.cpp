
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
// Node* getStartingNode(Node* head) {

//     if(head == NULL) 
//         return NULL;

//     Node* intersection = floydDetectLoop(head);
    
//     if(intersection == NULL)
//         return NULL;
    
//     Node* slow = head;

//     while(slow != intersection) {
//         slow = slow -> next;
//         intersection = intersection -> next;
//     }  

//     return slow;

// }

// ** Remove the Loop From LinkList
// Node *removeLoop(Node *head)
// {
//     if( head == NULL)
//         return NULL;

//     Node* startOfLoop = getStartingNode(head);
    
//     if(startOfLoop == NULL)
//         return head;
    
//     Node* temp = startOfLoop;

//     while(temp -> next != startOfLoop) {
//         temp = temp -> next;
//     } 

//     temp -> next = NULL;
//     return head;
// }