// class Solution
// {
//    private:
//     void insertAtTail(Node* &head, Node* &tail, int d) {
//         Node* newNode = new Node(d);
//         if(head == NULL) {
//             head = newNode;
//             tail = newNode;
//         }
//         else
//         {
//             tail -> next = newNode;
//             tail = newNode;
//         }
//     }
    
//     void print(Node* head) {
//         while(head != NULL) {
//             cout << head -> data << " ";
//             head = head -> next;
//         }cout << endl;
//     }

//     void printRandom(Node* head) {
//         while(head != NULL) {
//             cout << " head data: " << head->data <<" ";
//             if(head ->arb != NULL) {
//                 cout << " head random data" << head -> arb ->data;
//             }
//             else
//             {
//                 cout << " head random data: NULL";
//             }
//             head = head -> next;
//             cout << endl;
//         }
//     }

//     public:
//     Node *copyList(Node *head)
//     {
//         //step 1: Create a Clone List
//         Node* cloneHead = NULL;
//         Node* cloneTail = NULL;
        
//         Node* temp = head;
//         while(temp != NULL) {
//             insertAtTail(cloneHead, cloneTail, temp->data);
//             temp = temp -> next;
//         }
        
//         // step 2: insert nodes of Clone List in between originalList
        
//         Node* originalNode = head;
//         Node* cloneNode = cloneHead;
        
//         while(originalNode != NULL && cloneNode != NULL) {
//             Node* next = originalNode -> next;
//             originalNode -> next = cloneNode;
//             originalNode = next;
            
//             next = cloneNode -> next;
//             cloneNode -> next = originalNode;
//             cloneNode  = next;
//         }
        
//         // step 3: Random pointer copy
//         originalNode = head;
//         cloneNode = cloneHead;
        
//         while(originalNode != NULL && cloneNode != NULL) { 
            
//             if(originalNode -> arb != NULL) {
//                 cloneNode -> arb = originalNode -> arb -> next;
//             }
//             else
//             {
//                 cloneNode -> arb  = NULL;
//             }
            
//             cloneNode = cloneNode -> next;
//             originalNode = originalNode -> next;
//         }
        
//         //step 4: revert step 2 changes
//         Node* original = head;
//         Node* copy = cloneHead;
        
//          while (original && copy)
//             {
//                 original->next =
//                  original->next? original->next->next : original->next;
         
//                 copy->next = copy->next?copy->next->next:copy->next;
//                 original = original->next;
//                 copy = copy->next;
//             }

//         // step 5 answer return
//         return cloneHead;
//     }
// };


/*
class Solution
{
    public:
     void insert(Node *& head,Node *&tail,int data){
        Node * newNode = new Node(data);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            insert(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }
        
        //** Creation on Maping
        unordered_map<Node*,Node*> NodeMaping;
        temp = head;
        Node * cloneTemp = cloneHead;
        while(temp != NULL){
            NodeMaping[temp] = cloneTemp;
            temp = temp->next;
            cloneTemp = cloneTemp->next;
        }
        //** Set the Maping
        temp = head;
        cloneTemp = cloneHead;
        while(temp != NULL){
            cloneTemp->arb = NodeMaping[temp->arb];
            temp = temp->next;
            cloneTemp = cloneTemp->next;
        }
        return cloneHead;
    }

};*/



