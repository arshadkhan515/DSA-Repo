#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> temp;
    vector<int> ans(n);
    temp.push(-1);
    for(int i=n-1;i>=0;i--){  
        while(arr[i]<=temp.top()){
            temp.pop();
        }
        ans[i] = temp.top();
        temp.push(arr[i]);
    }
    return ans;
}