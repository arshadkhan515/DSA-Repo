// C++ program to find an element
// in an almost sorted array
#include <stdio.h>

int binarySearch(int * arr,int s,int e,int x){
    int mid = s+(e-s)/2;
    while (s<=e)
    {
        if(mid<e && arr[mid+1] == x)
        return mid+1;
        if(s<mid && arr[mid-1] == x)
        return mid-1;
        if(arr[mid] == x)
        return mid;

        if(arr[mid]>x)
         e = mid-2;
         else
         s= mid+2;
    }
    return -1;
}


// Driver Code
int main(void)
{
int arr[] = {3, 2, 10, 4, 40};
int n = sizeof(arr) / sizeof(arr[0]);
int x = 10;
int result = binarySearch(arr, 0, n - 1, x);
(result == -1) ? printf("Element is not present in array")
			: printf("Element is present at index %d",
						result);
return 0;
}