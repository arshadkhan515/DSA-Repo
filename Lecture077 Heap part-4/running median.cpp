// Running Median
// algo of this program is given in the book
//step 1 : condition of pushing a element in min heap is that it should be not empty and element should be greater than the top element of the min heap.or else we push it in the max heap.

// step 2 : check if the size of both the heap is different is greater than 1 then we pop the top element from the heap which has more elements.and push it in the heap which has less elements.

// step 3 : if the size of both the heap odd then we push the top element of the max size heap in the ans vector.otherwise we push the average of the top element of both the heap in the ans vector.
#include <bits/stdc++.h>
// https://www.youtube.com/watch?v=dshWERdcAdg
void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {

        if (!minHeap.empty() && arr[i] > minHeap.top())
        {
            minHeap.push(arr[i]);
        }
        else
        {
            maxHeap.push(arr[i]);
        }

        if (abs(maxHeap.size() - minHeap.size()) > 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        int total = maxHeap.size() + minHeap.size();
        int median = 0;

        if (total % 2 == 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                median = maxHeap.top();
            }
            else
            {
                median = minHeap.top();
            }
        }
        else
        {
            if (!maxHeap.empty() && !minHeap.empty())
            {
                median = maxHeap.top() + minHeap.top();
                median /= 2;
            }
        }

        cout << median << " ";
    }
}