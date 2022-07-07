#include<iostream>
using namespace std;

#include "4. Fraction.cpp"

int main() {
    Fraction f1(4, 3);
    Fraction f2(5, 4);
    f1+=(f1+=f2);
    f2.display();
    f1.display();

    Fraction f3(3, 4);
    Fraction f4(5, 10);
    Fraction product = f3 * f4;
    product.display();

    Fraction const f5(3, 4); // Constructor mien hi hoga change, otherwise no change
    f5.display();
    // f5.setNumerator(10);
    if(f5 == f4) {
        cout << "We are the same!\n";
    } else {
        cout << "We are not the same!\n";
    }

    // Pre-increment 
    f1.display();
    Fraction f6 = ++(++f1);
    f6.display();
    f1.display();
    ++f6;
    f6.display();
    f1.display();

    // Post-increment
    Fraction f7 = f1++;
    f7.display();
    f1.display();


}