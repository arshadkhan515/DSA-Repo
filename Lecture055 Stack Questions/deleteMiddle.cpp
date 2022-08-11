//? iterative Approach
void solve(stack<int>& input,int size,int count){
    stack<int> temp;
    while(count<size/2){
        temp.push(input.top());
        input.pop();
        count++;
    }
    input.pop();
    while(!temp.empty()){
        input.push(temp.top());
        temp.pop();
    }
}

//? Recursively Approach
void solve(stack<int>&inputStack, int count, int size) {
    //base case
    if(count == size/2) {
        inputStack.pop();
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
    
}

void deleteMiddle(stack<int>&inputStack, int N){
	
  	int count = 0;
    solve(inputStack, count, N);
   
}