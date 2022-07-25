//** Merge Two Sorted Linked Lists
// node* marge(node* first, node* second){

//     node* curr = first; 
//     node* next = curr->next; 
//     node* curr2 = second;  
//     node* next2 = curr2->next; 

//     if(next == NULL){
//         curr->next = curr2;
//     }
//     while(next != NULL && curr2 != NULL){
//         if(curr2->data >= curr->data && (curr2->data <= next->data)){
//             curr->next = curr2;
//             next2 = curr2->next;
//             curr2->next = next;
//             curr = curr2;
//             curr2 = next2;
//         }else{
//             curr = next;
//             next = curr->next;
//             if(next == NULL){
//                 curr->next = curr2;
//                 return first;
//             }
//         }
//     }
//     return first;
// }
// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
// {
//     if(first == NULL)
//         return second;
//     if(second == NULL)
//         return first;

//     if(first->data <= second->data){
//         return marge(first,second);
//     }else{
//         return marge(second,first);
//     }
// }

//? Approach 2
// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
//     if(!first)
//     {
//         return second;
//     }
//     if(!second)
//     {
//         return first;
//     }

//     if((first -> data) < (second ->data))
//     {
//         first -> next = sortTwoLists(first -> next, second);
//         return first;
//     }
//     else
//     {
//         second -> next = sortTwoLists(first, second -> next);
//         return second;
//     }
// }

//? Approach 3
// node* sortTwoLists(node* left,node* right) {
//     if(left == NULL)
//         return right;
    
//     if(right == NULL)
//         return left;
    
//     node* ans = new node(-1);
//     node* temp = ans;
    
//     //merge 2 sorted Linked List
//     while(left != NULL && right != NULL) {
//         if(left -> data < right -> data ) {
//             temp -> next = left;
//             temp = left;
//             left = left -> next;
//         }
//         else
//         {
//             temp -> next = right;
//             temp = right;
//             right = right -> next;
//         }
//     }
//     if(left != NULL) {
//         temp -> next = left;
//     }
//     if(right != NULL) {
//         temp -> next = right;
//     }
    
//     ans = ans -> next;
//     return ans;
// }