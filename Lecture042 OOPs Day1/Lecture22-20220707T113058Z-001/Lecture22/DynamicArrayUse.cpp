#include<iostream>
using namespace std;

#include "DynamicArray.cpp"

int main() {
    // Capacity = 5, Element = 0
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();
    cout << d1.get(7) << "\n";

    DynamicArray d2(d1);
    d2.print();
    
    DynamicArray d3;
    d3 = d1;
    d3.print();

    d1.add(11, 70);
    d1.add(0, 100);
    d1.print();
}