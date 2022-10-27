// Approach 1 using custom class

// step 1: we take all the first element of all the array and push them in the min heap.
// step 2: we push the top element of the min heap in the ans vector and pop the top element.
// step 3: we check current row and col its next element is present or not if present then we push it in the min heap.using current row and col+1.
// step 4: we repeat step 2 and 3 until the min heap is empty.
// time complexity O(n^klogk)
// space complexity O(k)

#include <bits/stdc++.h> 
class Base{
    public:
    int data;
    int row;
    int col;
    Base(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare{
    public:
    bool operator()(Base a,Base b){
        return a.data > b.data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Base,vector<Base>,compare> minHeap;
    vector<int> ans;
    for(int i = 0;i<k;i++){
        Base temp(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    while(minHeap.size() > 0){
        Base tmp = minHeap.top();
        minHeap.pop();
        ans.push_back(tmp.data);

        int row = tmp.row;
        int col = tmp.col;
        if(col+1 < kArrays[row].size()){
            Base newNode(kArrays[row][col+1],row,col+1);
            minHeap.push(newNode);
        }
    }
    return ans;
}



// Approach 2 using pair
// step 1: we take all the first element of all the array and push them in the min heap.
// step 2: we push the top element of the min heap in the ans vector and pop the top element.
// step 3: we check current row and col its next element is present or not if present then we push it in the min heap.using current row and col+1.
// step 4: we repeat step 2 and 3 until the min heap is empty.
// time complexity O(n^klogk)
// space complexity O(k)
#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
    vector<int> ans;
    for(int i = 0;i<k;i++){
        minHeap.push({kArrays[i][0],{i,0}});
    }
    while(minHeap.size() > 0){
        pair<int,pair<int,int>> tmp = minHeap.top();
        minHeap.pop();
        ans.push_back(tmp.first);

        int row = tmp.second.first;
        int col = tmp.second.second;
        if(col+1 < kArrays[row].size()){
            minHeap.push({kArrays[row][col+1],{row,col+1}});
        }
    }
    return ans;
}