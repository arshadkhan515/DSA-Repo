#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr,int n){
    if(n==1)
    return true;
    bool total = isSorted(arr+1,n-1);
    if(total)
    {
         if(arr[0] < arr[1])
         return true;
         else
         return false;
    }
    return total;
}
int sum(int *arr,int n){
    if(n==0)
    return n;

    int total = sum(arr,n-1);
    return arr[n-1] + total;
}
bool linerSearch(int *arr,int n,int target){
    if(n==0)
    return false;
    bool check = linerSearch(arr+1,n-1,target);
    if(!check){
        if(arr[0] == target)
        return true;
        else
        return false;
    }
    return check;
}
void insertEle(vector<int>& arr,int temp){
    if(arr.size()==0||arr.back() <= temp){
        arr.push_back(temp);
        return;
    }
    int val = arr.back();
    arr.pop_back();
    insertEle(arr,temp);
    arr.push_back(val);

}
void sortArray(vector<int> &arr){
    if(arr.size()==1)
    return;
    int temp = arr.back();
    arr.pop_back();
    sortArray(arr);
    insertEle(arr,temp);

}
void sortArray2(int *arr,int n){
    if(n==1)
    return;

    sortArray2(arr+1,n-1);
    int i=0;
    while(i<n-1){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
        i++;
    }

}

void insertStack(stack<int>& st,int ele){
    if(st.size() == 0)
    {
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    insertStack(st,ele);
    st.push(temp);

}

void reserverStack(stack<int>& st){
    if(st.size() == 1){
        return;
    }
    int temp = st.top();
    st.pop();
    reserverStack(st);
    insertStack(st,temp);
}

void insertArrayStack(stack<int>& st,int ele){
    if(st.size() == 0 || ele>=st.top())
    {
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    insertArrayStack(st,ele);
    st.push(temp);

}
void SortStack(stack<int>& st){
    if(st.size() == 1){
        return;
    }
    int temp = st.top();
    st.pop();
    SortStack(st);
    insertArrayStack(st,temp);
}
void deleteMid(stack<int>& st,int mid){
    if(mid==1){
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();
    deleteMid(st,mid-1);
    st.push(temp);
}

int main(){

    // vector<int> arr{10,20,300,40,50,45,7,0,8,7,1,3,2,10};
    // int arr[5] = {10,20,300,40,50};
    // cout<<linerSearch(arr,5,20);
    // cout<<sum(arr,5);
    // sortArray(arr,5);
    // sortArray2(arr,5);
    stack<int> st;
    st.push(1);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(2);
    st.push(4); 
    // reserverStack(st);
    // SortStack(st);
    // int mid = st.size()/2+1;
    // deleteMid(st,mid);
    while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
    }
    // for(auto i:st){
    //     cout<<i<<" ";
    // }
    return 0;
}