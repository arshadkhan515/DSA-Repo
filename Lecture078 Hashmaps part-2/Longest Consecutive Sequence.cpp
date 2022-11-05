// Leetcode 128 - Longest Consecutive Sequence - https://leetcode.com/problems/longest-consecutive-sequence/

// Approach 1: Using Hashmaps
// Time Complexity: O(n)
// Space Complexity: O(n)
// steps: 
// 1. insert all the elements in the hashmap and mark them as true
// 2. iterate over the array and check if the element-1 is present in the hashmap or not if not ,then we mark the false because the current element is the not the starting element of the sequence
// 3. And then we check only if the current element is the starting element of the sequence then we check for the next element in the sequence and we keep on incrementing the count and we update the maxLen
// https://www.youtube.com/watch?v=YWXbu5uyGXs&t=497s
#include <bits/stdc++.h>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    vector<int> ans;
    unordered_map<int, bool> M;
    int maxLen = 0;
    int maxStart = 0;
    int maxEnd = 0;

    for (int i = 0; i < n; i++)
    {
        M[arr[i]] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (M.count(arr[i] - 1))
        {
            M[arr[i]] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (M[arr[i]])
        {

            int len = 1;
            while (M.count(arr[i] + len))
            {
                len++;
            }

            if (len > maxLen)
            {
                maxLen = len;
                maxStart = arr[i];
            }
        }
    }
    for (int i = 0; i < maxLen; i++)
    {
        maxEnd = maxStart + i;
    }

    ans.push_back(maxStart);
    ans.push_back(maxEnd);

    return ans;
}