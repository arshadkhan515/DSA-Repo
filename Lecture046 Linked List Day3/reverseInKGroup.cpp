/*
Node *kReverse(Node *head, int k)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *pre = NULL;
    Node *curr = head;
    int i = 0;
    while (curr != NULL && i < k)
    {
        Node *forword = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forword;
        i++;
    }
    if (curr != NULL)
    {
        Node *newNode = kReverse(curr, k);
        head->next = newNode;
    }
    return pre;
}

*/

bool Is_LL_Circular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    if (head->next == NULL)
    {
        return false;
    }
    Node *temp = head->next;
    while (head != temp && temp != NULL)
    {
        temp = temp->next;
    }
    if (head == temp || temp == NULL)
    {
        return false;
    }
    return true;
}
