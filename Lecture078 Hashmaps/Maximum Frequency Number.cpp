// https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> m;
    
    int maxfeq = INT_MIN;
    int maxAn = 0;
    for(auto i:arr){
        m[i]++;
        maxfeq = max(maxfeq,m[i]);
    }
    for(auto i:arr){
        if(m[i] == maxfeq)
            return i;
    }
}