#include<cstring>

class Student2 {
    char* name;
    int rollNumber;
    public:
    Student2(int rollNumber, char* name) {
        this->rollNumber = rollNumber;
        // Shallow Copy (Should not be performed)
        // this->name = name;

        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void display() {
        cout << name << " " << rollNumber << "\n";
    }
};