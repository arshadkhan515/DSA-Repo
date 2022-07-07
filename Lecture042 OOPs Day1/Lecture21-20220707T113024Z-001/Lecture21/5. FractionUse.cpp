#include<iostream>
using namespace std;

#include "4. Fraction.cpp"

int main() {
    Fraction f1(4, 3);
    Fraction f2(5, 4);
    f1.add(f2);
    f1.display();

    Fraction f3(3, 4);
    Fraction f4(5, 10);
    f3.multiply(f4);
    f3.display();

    Fraction const f5(3, 4); // Constructor mien hi hoga change, otherwise no change
    f5.display();
    // f5.setNumerator(10);
}