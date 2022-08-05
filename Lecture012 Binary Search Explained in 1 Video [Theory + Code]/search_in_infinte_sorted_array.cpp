#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr, int s, int e, int key)
{

    int start = s;
    int end = e;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right wala part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        { // key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int Find_in_Infinite(vector<int> arr, int n, int k)
{
    int s = 0;
    int e = 0;

    while (e < n && arr[e] < k)
    {
        s = e;
        e += 4;
    }
    if (e >= n)
        e = n - 1;
    return binarySearch(arr, s, e, k);
}

int main()
{
    vector<int> letters{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int k = 16;

    // Function call
    int result = Find_in_Infinite(letters, letters.size(), k);
    cout << result << endl;
    return 0;
}