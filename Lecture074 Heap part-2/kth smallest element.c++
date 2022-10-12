// this is simple code for kth smallest element in array
// step 1. insert all the element in the min heap
// step 2. pop the element from the heap k-1 times and then return the top element.
// Approach 1
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<=r;i++){
            pq.push(arr[i]);
        }
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};

// In this approach we will use max heap
// step 1: we will insert first k element in the max heap because in max heap the top element will be the largest element.and its all element will be smaller than the top element.
// step 2: we will insert the remaining element in the heap and if the arr[i] is smaller than the top element of the heap then we will pop the top element and insert the arr[i] in the heap.
// step 3: after inserting all the element in the heap we will return the top element of the heap.
// Approach 2
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<=r;i++){
            if(arr[i] < pq.top()){
                 pq.pop();
                 pq.push(arr[i]);
            }
           
        }
        return pq.top();
    }
};