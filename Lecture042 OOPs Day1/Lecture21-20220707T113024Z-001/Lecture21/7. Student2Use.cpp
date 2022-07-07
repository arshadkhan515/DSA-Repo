#include<iostream>
using namespace std;

#include "6. Student2.cpp"

int main() {
    char name[] = "Mansi";
    Student2 student1(101, name);
    student1.display();
    // Manvi
    name[3] = 'v';
    Student2 student2(102, name);
    student2.display();
    // Mansi
    student1.display();
}