bool match(char input,char m){
    if((m == ')' && input == '(')
       ||
       (m == ']' && input == '[')
       ||
       (m == '}' && input == '{')){
        return true;
    }
    return false;
}
bool isValidParenthesis(string exp)
{
    stack<char> temp;
    for(auto i:exp){
        if(i == '(' || i == '[' || i == '{'){
            temp.push(i);
        }else{
            if(!temp.empty()){
                if(match(temp.top(),i))
                {
                    temp.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    return(temp.empty());
}