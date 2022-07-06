#include <iostream>
using namespace std;

int partition(int arr[],int s,int e){
 
  int count = 0;
  for(int i=s+1;i<=e;i++){
     if(arr[i] <= arr[s]){
        count++;
     }
  }
  int pivtInd = s+count;

  swap(arr[s],arr[pivtInd]);
  int i=s;
  int j=e;

  while(i<pivtInd && j>pivtInd){
    while(arr[i]<arr[pivtInd]){
        i++;
    }while(arr[j] > arr[pivtInd]){
        j--;
    }

    if(i<pivtInd && j>pivtInd){
        swap(arr[i++],arr[j--]);
    }
  }
return pivtInd;
}


void quickSort(int arr[],int s,int e){

    if(s>=e)
    return;

    int p = partition(arr,s,e);
    // cout<<arr[p]<<endl;
    // cout<<endl;
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int  main(){
    int arr[7] = {3,5,2,5,66,34,1};
    quickSort(arr,0,6);

    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}