class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        long long sum = 0;
        int i = 0,j=0;
        int n = nums.size();

        while(j<n){
            sum += nums[j];
            
            if(sum == k){
                ans++;
            }else if(sum > k){
                while(sum > k && i < j){
                    sum -= nums[i];
                    i++;
                    if(sum == k){
                        ans++;
                    }
                }
            }
            
            j++;

        }
        
        return ans;
    }
};
};