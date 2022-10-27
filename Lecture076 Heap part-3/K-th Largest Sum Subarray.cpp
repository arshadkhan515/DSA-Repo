// https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// Approach 1
// Time Complexity: O(n^2logn)
// Space Complexity: O(n^2)
#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
	priority_queue<int> AllSubArraySum;
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += arr[j];
            AllSubArraySum.push(sum);
        }
    }
    for(int i = 1;i<k;i++){
        AllSubArraySum.pop();
    }
    return AllSubArraySum.top();
}
// Approach 2
// time complexity O(n^2logk)
// space complexity O(k)
// we are using min heap of size k to store the k largest sum of subarray.
// we traverse the array and add the element in the min heap and if the size of the min heap is greater than k then we pop the top element. 
// at the end we return the top element of the min heap.
int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
	priority_queue<int,vector<int>,greater<int>> AllSubArraySum;
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += arr[j];
            if(AllSubArraySum.size()<k){
                AllSubArraySum.push(sum);            
            }else{
                if(sum > AllSubArraySum.top()){
                    AllSubArraySum.pop();
                    AllSubArraySum.push(sum);

                }
            }
        }
    }
    for(int i = 1;i<k;i++){
        AllSubArraySum.pop();
    }
    return AllSubArraySum.top();
}