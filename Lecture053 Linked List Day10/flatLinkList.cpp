/*
    Time Complexity: O(N * K)
    Space complexity: O(N)

    Where 'N' denotes the size of the linked list and 'K' is the average number of child nodes for each of the N nodes->
*/

// Node *merge(Node *first, Node *second)
// {
// If the first is NULL return second
//     if (first == NULL)
//     {
//         return second;
//     }

// If the second is NULL return first
//     if (second == NULL)
//     {
//         return first;
//     }

//     Node *merged = NULL;

//     if (first->data < second->data)
//     {
//         merged = first;
//         merged->child = merge(first->child, second);
//     }
//     else
//     {
//         merged = second;
//         merged->child = merge(first, second->child);
//     }
//     merged->next = nullptr;
//     return merged;
// }

// Node *flattenLinkedList(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }

// Recur on next node
//     head->next = flattenLinkedList(head->next);

// Merge with the current
//     head = merge(head, head->next);

//     return head;
// }

// ?Approach 2
// void insertAtTail(Node *&head, Node *&tail, int d)
// {
//     Node *newNode = new Node(d);
//     if (head == NULL)
//     {
//         head = newNode;
//         tail = newNode;
//     }
//     else
//     {
//         tail->next = newNode;
//         tail = newNode;
//     }
// }
// Node *flattenLinkedList(Node *head)
// {
//     vector<int> ansStore;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         ansStore.push_back(temp->data);

//         Node *temp2 = temp;
//         while (temp2 != NULL)
//         {
//             ansStore.push_back(temp2->child->data);
//             temp2 = temp2->child;
//         }
//         temp = temp->next;
//     }
//     sort(ansStore.begin(), ansStore.end());

//     Node *ansHead = NULL;
//     Node *ansTail = NULL;
//     for (auto i : ansStore)
//     {
//         insertAtTail(ansHead, ansTail, i);
//     }
//     //      while(ansHead  != NULL){
//     //              cout<<ansHead->data<<" ";
//     //             ansHead = ansHead->next;
//     //         }
//     return ansHead;
// }
