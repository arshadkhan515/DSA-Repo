// Repeat 
//{ Driver Code Starts
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








vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    int i=0;
    int j=0;
    vector<long long> ans;
    
    for(int i=0;i<N;i++){
        long temp = 0;
        bool flag = false;
        for(int j=i;j<N;j++){
            
            if(flag == false && j-i+1 < k && A[j] < 0){
                  temp = A[j];
                  flag = true;
            }else if(j-i+1 == k){
                 if(flag == false && A[j] < 0){
                  temp = A[j];
                }
                ans.push_back(temp);
            }
            
        }
    }
    return ans;
    
    
    
 }


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         deque<long long int> dq;
         vector<long long> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<K; i++) {
             if(A[i] < 0) {
                 dq.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(A[dq.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=K ) {
                 dq.pop_front();
             }
             
             //then push current element
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }