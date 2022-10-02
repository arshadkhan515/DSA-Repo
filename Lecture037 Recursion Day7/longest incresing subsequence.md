# Longest incresing subsequence
- is a classic problem in Computer Science. Given a sequence of numbers, find the longest
incresing subsequence. 
- For example, given the sequence “5, 3, 4, 8, 6, 7”, the
longest incresing subsequence is “3, 4, 6, 7”. 


## this Approach is use include and exclude method to solve this problem 
- we check for every element if it is greater than the last element of the current subsequence 
- if it is greater then we include it in the current subsequence and check for the remaining elements
- if it is not greater then we exclude it and check for the remaining elements
- we return the maximum of the two cases
- but this appoach is giving TLE in leetcode but it is working fine in my local machine
- because this problem is dynamic programming problem and we can solve it using dynamic programming

```cpp:
class Solution {
public:
    int solve(vector<int>& nums,int curr,int pre){
        if(curr == nums.size()){            
            return 0;
        }
        
        // include
        int pick = 0;
        if(pre == -1 || nums[pre] < nums[curr]){
           pick = 1+solve(nums,curr+1,curr);
        }
        
        // exclude
        int notpick = 0;
        notpick = solve(nums,curr+1,pre);
        
        return max(notpick,pick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int pre = -1;
        int curr = 0;
        return solve(nums,curr,pre);
    }
};
```
