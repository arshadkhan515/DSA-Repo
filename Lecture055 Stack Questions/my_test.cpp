#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s)
{
    stack<char> temp;
    for (auto i : s)
    {
        temp.push(i);
    }
    int i = 0;
    while (!temp.empty())
    {
        s[i] = temp.top();
        temp.pop();
        i++;
    }
}
void pushAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    pushAtBottom(myStack, x);
    myStack.push(num);
}
void reverseStack(stack<int> &myStack)
{
    if (myStack.empty() || myStack.size() == 1)
    {
        return;
    }
        cout<<"a";

    int num = myStack.top();
    myStack.pop();
    reverseStack(myStack);
    pushAtBottom(myStack, num);
}

int main()
{

    // string s = "123456";
    // cout << s<<endl;
    // reverseString(s);
    // cout << s<<endl;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    reverseStack(s);

    return 0;
}