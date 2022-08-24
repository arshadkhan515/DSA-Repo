#include <bits/stdc++.h>
using namespace std;

//? This code is most important ans this is sliding window 
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    int i=0;
    int j=0;
    queue<long long> q;
    vector<long long> ans;
    
    while(j<N){
        if(A[j]<0){
            q.push(j);
        }
        
       if(j-i+1 < k){
           j++;
       }else if(j-i+1 == k){
           if(q.empty()){
               ans.push_back(0);
           }else{
               ans.push_back(A[q.front()]);
           }
       
           if(!q.empty() && i==q.front()){
               q.pop();
           }
           i++;
           j++;
       }
       
    }
    return ans;
    
    
    
 }
