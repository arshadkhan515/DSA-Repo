#include<stack>

bool findRedundantBrackets(string &s)
{
    stack<char> temp;
    for(auto i:s){
        if(i == '(' || (i >= 42 && i<=47)){
            temp.push(i);
        }else{
            if(i == ')'){
                bool ans = true;
                while(!temp.empty() && temp.top() != '('){
                    if(temp.top()>= 42 && temp.top() <= 47){
                        ans = false;
                        temp.pop();
                    }                  
                }
                if(ans)
                    return ans;
                if(!temp.empty())
                    temp.pop();
            }
        }
    }
    return false;
}
