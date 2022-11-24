#include<iostream>
#include<math.h>
using namespace std;

// https://stackoverflow.com/questions/5771520/why-is-the-maximum-value-of-an-unsigned-n-bit-integer-2%E2%81%BF-1-and-not-2%E2%81%BF
int main() {

    int n;
    cin >> n;

    int i = 0, ans = 0 ;

    while( n != 0) {

        int digit = n % 10;

        if( digit == 1) {
            ans = ans + pow(2, i);
        }

        n = n/10;
        i++;

    }
    cout<< ans << endl;
    return 0;
}