//** Reverse LinkList
/*class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
*/
/*
class Solution
{
public:
    void solve(ListNode *&head, ListNode *pre, ListNode *curr)
    {
        if (curr == NULL)
        {
            head = pre;
            return;
        }

        solve(head, curr, curr->next);
        curr->next = pre;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *pre = NULL;
        ListNode *forword = NULL;

        while (curr != NULL)
        {
            forword = curr->next;
            curr->next = pre;
            pre = curr;
            curr = forword;
        }
        solve(head, NULL, head);
        return head;
    }
};
*/

// ** Middle Of linkList
/*
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    */

//**  reverse Doubly Linklist
/*
struct Node* reverseDLL(struct Node * head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }

   struct Node * newhead = reverseDLL(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    return newhead;
}
*/