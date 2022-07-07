#include<cstring>

class Student3 {
    // char* name;
    int const rollNumber;
    int age;
    int &x;

    public:
    Student3() : rollNumber(100), x(this->age) {
        this->age = 10;
    }
    Student3(int r, int a) : rollNumber(r), x(this -> age) {
        // NOT APPLICABLE (CONST)
        // this->rollNumber = rollNumber;

        // NOT APPLICABLE (REFERENCE)
        // x = age;
        age = a;
        // Shallow Copy (Should not be performed)
        // this->name = name;

        // Deep Copy
        // this->name = new char[strlen(name) + 1];
        // strcpy(this->name, name);
    }
    void display() {
        cout << age << " " << rollNumber << "\n";
    }
};