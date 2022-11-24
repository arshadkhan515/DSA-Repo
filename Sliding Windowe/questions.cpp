// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long current = 0;
        long long maxSum = 0;
        
        // make a first window
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            current += nums[i];
        }
        // if all element is unique the store it
        if(mp.size() == k){
            maxSum = current;
        }
        // slide the window for reaming part
        for(int i=k;i<nums.size();i++){
            // remove start of the window
            mp[nums[i-k]]--;
            current -= nums[i-k];
            
            if(mp[nums[i-k]] == 0){
                mp.erase(nums[i-k]);
            }
            // slide the window increment end of the window
            mp[nums[i]]++;
            current += nums[i];
            // and check all element is unique or not 
            if(mp.size() == k){
               maxSum = max(current,maxSum);
            }
        }

        
        return maxSum;
    }
};