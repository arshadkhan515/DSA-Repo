#include <iostream>
using namespace std;

void margeTwoSorted(int arr[],int s,int e){

    int mid = (s+e)/2;
    int *temp = new int[e-s+1];

    int tempInd = 0;
    int firstStart = s;
    int secondStart = mid+1;
    
    while(firstStart <= mid && secondStart <= e){
        if(arr[firstStart] < arr[secondStart]){
             temp[tempInd++] = arr[firstStart++];
        }else{
             temp[tempInd++] = arr[secondStart++];
            //  int count += 
        }
    }

    while(firstStart <= mid){
        temp[tempInd++] = arr[firstStart++];
    }
    while(secondStart <= e){
        temp[tempInd++] = arr[secondStart++];
    }

    tempInd = 0;
    for(int i=s;i<e+1;i++){
        arr[i] = temp[tempInd++];
    }

}


void margeSort(int arr[],int s,int e){

    if(s>=e)
    return;

    int mid = (s+e)/2;
    margeSort(arr,s,mid);
    margeSort(arr,mid+1,e);
    margeTwoSorted(arr,s,e);
}

int main(){
 
    int arr[7] = {3,5,2,5,66,34,1};
    margeSort(arr,0,6);

for(auto i:arr){
    cout<<i<<endl;
}
    return 0;
}