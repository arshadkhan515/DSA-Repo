void solve(stack<int>& s, int x) {
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    solve(s, x);
    
    s.push(num);
}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}

//? MY Approach
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }
    
    int num = myStack.top();
    myStack.pop();
    stack<int> newStack = pushAtBottom(myStack,x);
    newStack.push(num);
    return newStack;
}
