#include<iostream>
using namespace std;

#include "9. Student4.cpp"

int Student4::totalStudents = 0; // Initialise outside main (Static)
int main() {
    Student4 s1(101, 18);
    Student4 s2(101, 18);
    Student4 s3(101, 18);
    Student4 s4(101, 18);
    Student4 s5(101, 18);
    cout << Student4::getTotalStudents() << endl;
}