#include<bits/stdc++.h>
int findMinimumCost(string str) {
    if(str.size() % 2 == 1)
        return -1;
    stack<int> temp;
    for(auto i:str){
        if(i == '{'){
            temp.push(i);
        }else{
            if(!temp.empty() && temp.top() == '{'){
                temp.pop();
            }else{
                temp.push(i);
            }
        }
    }
    int a = 0,b=0;
    while(!temp.empty()){
        if(temp.top() == '{'){
            a++;
        }else{
            b++;
        }
        temp.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}