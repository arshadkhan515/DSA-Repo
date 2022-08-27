#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    // *
    // **
    // ***
    // ****
    // *****
    // ****
    // ***
    // **
    // *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (i * 2) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= ((n - i + 1) * 2) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (j & 1 == 1)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    // 1      1
    // 12    21
    // 123  321
    // 12344321

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        for (int j = 1; j <= ((n - i + 1) * 2) - 2; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********

    // first part
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= (i * 2) - 2; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // second part
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= ((n - i + 1) * 2) - 2; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *

    // part part
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= ((n - i + 1) * 2) - 2; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // second part
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= (i * 2); j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern7(int n)
{
    // ******
    // *    *
    // *    *
    // *    *
    // ******

    // part part
    for (int i = 1; i <= n; i++)
    {
        cout << "*";

        for (int j = 1; j <= n - i; j++)
        {
            if (i == 1)
                cout << "*";
            else
                cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            if (j == i)
                cout << "*";
            else if (i == n)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num;
    cin >> num;
    cout << endl;
    // pattern1(num);
    // pattern2(num);
    // pattern3(num);
    // pattern4(num);
    // pattern5(num);
    // pattern6(num);
    pattern7(num);
    cout << endl;

    return 0;
}