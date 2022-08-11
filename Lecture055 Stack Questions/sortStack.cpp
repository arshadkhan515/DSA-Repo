void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}

//? My Approach
void insertEle(stack<int>&inputStack,int x) {
    //base case
    if(inputStack.empty() || x > inputStack.top())
    {
        inputStack.push(x);
        return ; 
    }

    int num = inputStack.top();
    inputStack.pop();

    //RECURSIVE CALL
    insertEle(inputStack, x);

    inputStack.push(num);

}

void sortStack(stack<int> &myStack)
{
    if(myStack.empty() || myStack.size() == 1){
        return;
    }
    int num = myStack.top();
    myStack.pop();
    sortStack(myStack);
    insertEle(myStack,num); 
}