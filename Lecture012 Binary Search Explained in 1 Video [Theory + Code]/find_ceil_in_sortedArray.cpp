int findFloor(long long int arr[], int N, long long int x)
{

    int s = 0, e = N - 1;
    int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}