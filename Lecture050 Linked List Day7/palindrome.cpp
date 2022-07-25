//**Check if Linked List is Palindrome
// class Solution
// {
// private:
//     Node *reverse(Node *head)
//     {
//         if (head == NULL || head->next == NULL)
//         {
//             return head;
//         }

//         Node *newHead = reverse(head->next);
//         Node *temp = newHead;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = head;
//         head->next = NULL;
//         return newHead;
//     }

// public:
//     // Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         if (head->next == NULL)
//         {
//             return true;
//         }

//         // step 1 -> find Middle
//         Node *slow = head;
//         Node *fast = head->next;

//         while (fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // step2 -> reverse List after Middle
//         slow->next = reverse(slow->next);

//         // step3 - Compare both halves
//         Node *p1 = head;
//         Node *p2 = slow->next;

//         while (p2 != NULL)
//         {
//             if (p1->data != p2->data)
//             {
//                 return false;
//             }
//             p1 = p1->next;
//             p2 = p2->next;
//         }

//         // step4 - repeat step 2(Option)
//         slow->next = reverse(slow->next);

//         return true;
//     }
// };