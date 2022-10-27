//** Heap Data Structure - Introduction

//** 1. Heap is a special tree based data structure in which the tree is a complete binary tree.
// CBT - complete binary tree - every level is completely filled except possibly the last level and the last level has all keys as left as possible.


// **2. A heap is di
// explanation - the value of the parent node is always greater than or equal to the value of the child node. (max heap)
// explanation - the value of the parent node is always less than or equal to the value of the child node. (min heap)

// image of normal heap - https://upload.wikimedia.org/wikipedia/commons/thumb/c/c4/Max-Heap-new.svg/1200px-Max-Heap-new.svg.png
// image - https://www.geeksforgeeks.org/wp-content/uploads/MinHeapAndMaxHeap.png


//** 3. Heap is used to implement priority queues. Priority queues are very important in competitive programming.


// for representation of heap we use array.  (we can use linked list also but array is better)
// because in array we can access any element in O(1) time.
// in linked list we can access any element in O(n) time.

// the time complexity of heap operations is O(log n) time.
// and insertion and deletion is O(log n) time.
// here n is the number of elements in the heap.
