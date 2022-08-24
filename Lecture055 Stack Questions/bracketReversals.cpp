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

#include<stack>
int countBracketReversals(string input) {
    stack<char> s;
    int count = 0;
    
    if(input.size()%2 == 0){

        for(auto i:input){
            if(i == '{'){
                s.push(i);
            }else{
                if(!s.empty() && s.top() == '{'){
                       s.pop();
                }else{
                    s.push(i);
                }

            }
        }
        // Peek two bracket from the stack and compare them if both is equal then increment 1 otherwise 2
        
        //*   }{ this bracket make balance for reverse two times
        while(!s.empty()){
            char a = s.top();
            s.pop();
            char b = s.top();
            s.pop();
            if(a == b){
                count++;
            }else{
                count += 2;
            }
        }
    }else{
        return -1;
    }
    return count;
}