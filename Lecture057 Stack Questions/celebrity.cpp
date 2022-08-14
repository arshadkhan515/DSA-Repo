//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
//? My Code 
class Solution 
{
    public:
    bool khows(vector<vector<int> >& M, int a,int b){
        if(M[a][b] == 1)
        return true;
        else
        return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int> temp;
       for(int i=0;i<n;i++){
           temp.push(i);
       }
       
       while(temp.size() != 1){
           int a = temp.top();
           temp.pop();
           int b = temp.top();
           temp.pop();
           
           if(khows(M,a,b)){
               temp.push(b);
           }else{
               temp.push(a);
           }
       }
       int possibleCondidet = temp.top();
       // Step 3: to Validate possibleCondidet Celebrity or not
    
       //Check in Row
       int countZeroInRow = 0;
       for(int i=0;i<n;i++){
           if(M[possibleCondidet][i] == 0){
               countZeroInRow++;
           }
       }
       if(countZeroInRow != n)
       return -1;
       
       // Check in Colume
       int countOneInColume = 0;
       for(int i=0;i<n;i++){
           if(M[i][possibleCondidet] == 1){
               countOneInColume++;
           }
       }
       
       if(countOneInColume != n-1)
       return -1;
       
       return possibleCondidet;
       
    }
};

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and compare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        // Row Check
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends

// ?  Brute Force Approach
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       for(int i=0;i<M.size();i++){
           bool c = true;
           bool p = true;
           
           for(int j=0;j<M[i].size();j++){
               if(M[i][j] == 1){
                   c = false;
               }
           }
           
           for(int x=0;x<M.size();x++){
               if(M[i][i] == 0)
               continue;
               if(M[x][i] == 0){
                   p = false;
               }
           }
           
           if(c && p){
               return 1;
           }
       }
       return -1;
    }
};