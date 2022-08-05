#include <bits/stdc++.h>
using namespace std;

char Next_Alphabetical_Element(vector<char> alpha, int n, int k)
{
    if (k >= alpha[n - 1])
        return alpha[0];

    int s = 0, e = n - 1;
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (alpha[mid] > k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return alpha[ans];
}

int main()
{
    vector<char> letters{ 'A', 'K', 'S' };
    char K = 'A';
 
    // Function call
    char result = Next_Alphabetical_Element(letters,letters.size(), K);
    cout << result << endl;
    return 0;
}