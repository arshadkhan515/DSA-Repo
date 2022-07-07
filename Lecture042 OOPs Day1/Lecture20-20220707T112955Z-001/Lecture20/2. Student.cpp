class Student {
    int rollNumber;
    int adharNumber;
    void print() {
        cout << "Calling Address:" << this << endl;
        cout << "Hello" << endl;
    }
    public:
    // Default Constructor
    Student() {
        cout << "Object Created!" << endl;
        // rollNumber = 0;
        // adharNumber = 0;
    }
    // Parameterized Constructor
    Student(int rollNumber, int adharNumber) {
        cout << "Parameterized Constructor called!" << endl;
        this -> rollNumber = rollNumber;
        this -> adharNumber = adharNumber;
    }
    Student(int rn) {
        cout << "Parameterized Constructor 2 called!" << endl;
        rollNumber = rn;
    }
    void setRollNumber(int rn) {
        // if(password != 123)
        //     return;
        rollNumber = rn;
    }
    void setAdharNumber(int an) {
        adharNumber = an;
    }
    int getRollNumber() {
        print();
        return rollNumber;
    }
    int getAdharNumber() {
        return adharNumber;
    }
    ~Student() {
        cout << "Destructor Called!" << endl;
    }
}