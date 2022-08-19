// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int start = 0;
       int balance = 0;
       int distanc = 0;
       
       for(int i=0;i<n;i++){
           balance = balance+ p[i].petrol - p[i].distance;
           
           if(balance < 0){
               distanc += balance;
               start = i+1;
               balance = 0;
           }
       }
       if(distanc + balance >=0){
           return start;
       }else{
           return -1;
       }
       
    }
};



// { Driver Code Starts.

// ?Brute Force 
int fun(int* p,int n){
    for(int i=0;i<n;i++){
        int forward = i;
        int balance  = 0;

        while (true)
        {
            balance += p[forward].petrol - p[forward].dis;
            if(balance < 0){
                break;
            }else{
                forward = (forward+1)%n;
            }
            if(i==forward){
                return i;
            }
        }
        
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends