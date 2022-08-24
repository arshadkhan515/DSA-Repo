#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int start =0;
        int end= 0;
        long ans = 0;
        long sum = 0;
        
        while(end<N){
            sum += Arr[end];
            if(end-start+1 < K){
                end++;
            }else if(end-start+1 == K){
                ans = max(ans,sum);
                sum -= Arr[start];
                start++;
                end++;
            }
        }
        return ans;
    }
};