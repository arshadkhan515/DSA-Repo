// Longest Subarray Zero Sum using Hashmaps
// https://www.codingninjas.com/codestudio/problems/longest-subset-zero-sum_920321?leftPanelTab=0

// Approach 2: Using Hashmaps
// Time Complexity: O(n)
// Space Complexity: O(n)
// image of approach
// https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190702111822/LenghtOfLargestSubarrayWithOSum.png

#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> M;
    int maxLen = 0;
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];

        if(sum == 0)
            maxLen = i+1;

        if(M.count(sum)){
            maxLen = max(maxLen,i-M[sum]);
        }else{
            M[sum] = i;
        }
    }
    return maxLen;
}