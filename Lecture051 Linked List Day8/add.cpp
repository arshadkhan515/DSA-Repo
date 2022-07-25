/*class Solution
{
    private:
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        
        Node* temp = new Node(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 - add 2 LL
        Node* ans = add(first, second);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
    }
};*/
// **My Code 
/*class Solution
{
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
    void insert(ListNode *& head,ListNode *&tail,int data){
        ListNode * newNode = new ListNode(data);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

    }
    
    ListNode* add(struct ListNode* Fhead, struct ListNode* Shead){
        int sum = 0;
        int D = 0;
        ListNode * ansHead = NULL;
        ListNode * ansTail = NULL;
        
        while(Fhead != NULL || Shead != NULL || D != 0){
            
            int val1 = 0;
            if(Fhead != NULL)
            val1 = Fhead ->data;
             
            int val2 = 0;
            if(Shead != NULL)
            val2 = Shead->data;
             
             
            sum = (val1 + val2) + D;
            
            int getLast = sum%10;
            insert(ansHead,ansTail,getLast);
            
            D = sum/10;
            
            if(Fhead != NULL)
            Fhead =Fhead->next;
              if(Shead != NULL)
            Shead = Shead->next;
        }
      
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct ListNode* addTwoLists(struct ListNode* first, struct ListNode* second)
    {
        ListNode* Fhead = reverseList(first);
        ListNode* Shead = reverseList(second);
        
        ListNode * SumHead = add(Fhead,Shead);
        SumHead = reverseList(SumHead);
        // cout<<sum<<endl;
        return SumHead;
        
    }
};*/