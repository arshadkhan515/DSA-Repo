//*** in the heap we store the elements in the array in level order. (from left to right).
// for 0 based indexing, the left child of the node at index i is at index 2*i+1 and the right child is at index 2*i+2.
// for 1 based indexing, the left child of the node at index i is at index 2*i and the right child is at index 2*i+1.

/* for 0 based indexing, the parent of the node at index i is at index (i-1)/2.
 for 1 based indexing, the parent of the node at index i is at index i/2.*/




//*** meaning of the heapify function:
// we have to make sure that the parent node is greater than the child node.(max heap)
// we have to make sure that the parent node is smaller than the child node.(min heap)

#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;

    Heap (){
        arr[0] = -1;
        size = 0;
    }

    // for inserting the element in the heap. we have to insert the element in the last position of the array.
    // then use the bottom-up heapify function to make sure that the heap property is satisfied.
    void insertInHeap(int data){
           // insert in Max Heap

           size++;
           arr[size] = data;
           int indx = size;

           while(indx > 1){    
              int parent = (indx)/2;
              // to make (min-heap) to (max-heap) change only if condition
              if(arr[parent] < arr[indx]){
                    swap(arr[parent],arr[indx]);                  
              }else{
                return;
              }
             indx = parent;
           }

    }

    //** in delete we have to delete the root node and then we have to heapify the tree.
    // 1. for deleting the root node we have to swap the root node with the last node and then delete the last node.
    // 2. then we have to top-down heapify the tree.

    void deleteInHeap(){
        // delete In Max heap
        
        // step 1 put the last element in (root or first postion)
        arr[1] = arr[size];
        size--;

        // here i is represent parent element
        int i = 1;
        while(i < size){

            // and find maxIndex and swap with parent element
            int maxIndx = i;
            int leftInd = i*2;
            int rightInd = (i*2)+1;

            if(leftInd <= size && arr[leftInd] > arr[maxIndx]){
                maxIndx = leftInd;
            }

             if(rightInd <= size && arr[rightInd] > arr[maxIndx]){
                maxIndx = rightInd;
            }

            if(i==maxIndx){
                break;
            }

            swap(arr[maxIndx],arr[i]);
            i = maxIndx;
        }

    }

    void print(){
            for(int i = 1;i<=size;i++){

                cout<<"Root:"<<arr[i]<<" ";

                if(i*2 <= size)
                    cout<<"Left:"<<arr[i*2]<<", ";

                if((i*2)+1 <= size){
                    cout<<"Right:"<<arr[(i*2)+1];
                }

                cout<<endl;

            }
    }

};

void heapify(int*arr,int n,int i){
    //*** Min-Heap
    /*int minInd = i;
    int leftInd = 2*i+1;
    int rightInd = (2*i)+2;

    if(leftInd < n && arr[leftInd] < arr[minInd]){
        minInd = leftInd;
    }

    if(rightInd < n && arr[rightInd] < arr[minInd]){
        minInd = rightInd;
    }

    if(i!=minInd){
        swap(arr[i],arr[minInd]);
        heapify(arr,n,minInd);
    }*/

    //*** Max-Heap 
    int maxInd = i;
    int leftInd = 2*i+1;
    int rightInd = (2*i)+2;

    if(leftInd < n && arr[leftInd] > arr[maxInd]){
        maxInd = leftInd;
    }

    if(rightInd < n && arr[rightInd] > arr[maxInd]){
        maxInd = rightInd;
    }

    if(i!=maxInd){
        swap(arr[i],arr[maxInd]);
        heapify(arr,n,maxInd);
    }
}

int main(){
     
     Heap * newOp = new Heap();
    //  newOp->insertInHeap(5);
    //  newOp->insertInHeap(10);
    //  newOp->insertInHeap(20);
    //  newOp->insertInHeap(8);
    //  newOp->insertInHeap(9);
    //  newOp->insertInHeap(25);
    //  newOp->insertInHeap(1);
    //  newOp->deleteInHeap();
    //  newOp->print();

    int arr[7] = {50,45,12,98,78,65,10};
    int n = 7;
    //*** here you can use n/2 for starting point of loop
    // because n/2 to n are leaf nodes and leaf nodes are already heapify so we don't need to heapify them.In Complete Binary Tree.
    for(int i=n/2;i>=0;i--){
        heapify(arr,n,i);
    }

    //**** heap sort algo step
    // 1. heapify the array
    // 2. swap the root node with the last node and then delete the last node.
    // 3. heapify the tree again.on the remaining tree.
    // 4. repeat step 2 and 3 until the size of the heap is 1.
    for(int i=0;i<n;i++){
        swap(arr[0],arr[n-i-1]);
        heapify(arr,n-i-1,0);
    }
    
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }cout<<endl;



    //*** for use heap property in stl then use priority_queue
    //default is max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    // for get the top element
    cout<<pq.top()<<endl;
    // for delete the top element
    pq.pop();
    cout<<pq.top()<<endl;
    // for get the size of the heap
    cout<<pq.size()<<endl;
    // for check the heap is empty or not
    cout<<pq.empty()<<endl;

    //** for min heap
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(10);
    pq1.push(20);
    pq1.push(30);
    pq1.push(40);
    // for get the top element
    cout<<pq1.top()<<endl;
    // for delete the top element
    pq1.pop();
    cout<<pq1.top()<<endl;
    // for get the size of the heap
    cout<<pq1.size()<<endl;
    // for check the heap is empty or not
    cout<<pq1.empty()<<endl;

    return 0;
}