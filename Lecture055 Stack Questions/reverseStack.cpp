
void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}

void reverseStack(stack<int> &stack) {
  	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}


///? My Approach
void pushAtBottom(stack<int>& myStack, int x) 
{
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    pushAtBottom(myStack,x);
    myStack.push(num);
}
void reverseStack(stack<int> &myStack) {
    if(myStack.empty() || myStack.size() == 1){
        return;
    }
    int num = myStack.top();
    myStack.pop();
    reverseStack(myStack);
    pushAtBottom(myStack,num); 
}