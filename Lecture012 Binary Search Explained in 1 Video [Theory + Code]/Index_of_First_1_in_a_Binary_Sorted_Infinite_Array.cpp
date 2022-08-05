#include <bits/stdc++.h>
using namespace std;
int firstLastPosition(vector<int> arr, int s, int e, int key)
{

    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        { // Right me jao
            s = mid + 1;
        }
        else if (key < arr[mid])
        { // left me jao
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
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
    return firstLastPosition(arr, s, e, k);
}

int main()
{
    vector<int> letters{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int k = 1;

    // Function call
    int result = Find_in_Infinite(letters, letters.size(), k);
    cout << result << endl;
    return 0;
}