#include<iostream>
using namespace std;

#include "2. Student.cpp"

int main() {
    Student nishant;
    // nishant.rollNumber = 40;
    // nishant.adharNumber = 50;
    // cout << nishant.getRollNumber() << endl;
    // nishant.setRollNumber(40);
    // nishant.print();
    cout << "Address of Nishant: " << &nishant << endl;
    cout << nishant.getRollNumber() << endl;


    Student *mansi = new Student();
    // (*mansi).setRollNumber(60);
    // // -> (Arrow Operator)
    // mansi -> setAdharNumber(100);
    // cout << (*mansi).getRollNumber() << endl;
    cout << mansi -> getAdharNumber() << endl;

    // Student ritik(30, 50);
    // Student sakshi(30);
    delete mansi;
}