class Student4{
    int rollNumber;
    int age;
    static int totalStudents;
    
    public:
    Student4(int rollNumber, int age) {
        this->rollNumber = rollNumber;
        this->age = age;
        totalStudents++;
    }
    int getRollNumber() {
        totalStudents = 100;
        return rollNumber;
    }
    static int getTotalStudents() {
        // NON-STATIC PROPERTIES CANNOT BE ACCESSED HERE.
        // return rollNumber;
        // getRollNumber();
        return totalStudents;
    }
};