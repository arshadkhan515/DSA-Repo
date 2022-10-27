// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Approach is same as Merge K Sorted Arrays with some changes
// step 1: we take all the first element of all the array and push them in the min heap.
// step 2: to create head and tail pointer of the linked list
// step 3: if head is null then we make head and tail point to the top element of the min heap
// step 4: if head is not null then we make tail->next point to the top element of the min heap and tail = tail->next
// step 5: we pop the top element of the min heap
// step 6: we check current node its next element is present or not if present then we push it in the min heap.
// step 7: we repeat step 2 and 3 until the min heap is empty.
#include<bits/stdc++.h>
class compare{
    public:
    bool operator()(Node<int>* a,Node<int>* b){
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare> minHeap;

    for(auto i:listArray){
        if(i!=NULL){
            minHeap.push(i);
        }
    }
    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while(!minHeap.empty()){
        Node<int>* takeNewNode = minHeap.top();
        minHeap.pop();
        if(head == NULL){
            head = tail = takeNewNode;            
        }else{
            tail->next = takeNewNode;
            tail = takeNewNode;
        }
        if(tail->next != NULL){
            minHeap.push(tail->next);
        }
    }
    //     tail->next = NULL;
    return head;
}
