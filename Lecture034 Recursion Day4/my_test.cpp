#include<bits/stdc++.h> 
using namespace std;

void reverseS(string &str,int s){
    if(s>=str.size()-s-1)
    return;
    swap(str[s],str[str.size()-s-1]);
    reverseS(str,s+1);
}
int findPower(int di,int pw){
 if(pw == 0)
   return 1;

   int ans = findPower(di,pw-1);
   return ans*di;

}
void bubble(int *arr,int n){
if(n==1)
return;
    bubble(arr+1,n-1);
    int i=0;
    while(i<n-1){
        if(arr[i] > arr[i+1])
        swap(arr[i],arr[i+1]);
        i++;
    }

}
int main(){

    int arr[9] = {10,200,300,40,50,2,35,43,34};
    bubble(arr,9);
    for(auto i:arr)
    cout<<i<<endl;
    // cout<<linerSearch(arr,5,20);
    string str = "ababa";
    // cout<<checkPalindrome(str,0);
    // cout<<findPower(2,8);
    // for(auto s:str){
    //     cout<<s;
    // }
    return 0;
}