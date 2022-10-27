// Minimum Cost of ropes
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0
// Approach 1
// step 1: create priority queue and insert all element of array in it.
// step 2: then pop two element and add them and push in priority queue.(because we need to connect two ropes that means we need two smallest element)
// step 3: to make sum of all ropes.
// step 4: repeat step 2 until the size of the priority queue is 1.
// step 5: return the sum.
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(int i = 0;i<n;i++){
            pq.push(arr[i]);
        }
        long long ans = 0;
        while(pq.size() != 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a+b;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};