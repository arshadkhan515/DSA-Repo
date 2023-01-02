//** What is the time and space complexity?
// How do algorithms scale as the input size grows larger and larger.

// **steps to calculate time complexity
// 1. count the number of operations(assignment, comparison, addition, multiplication, etc.) or time complexity always find the worst case
//** example of loop constant time complexity
// for (int i = 0; i < 5; i++) {
//     cout << i << endl;
// } number of operations is 15, because 3 operations for each loop(assignment, comparison, increment) and 5 loops so 3 * 5 = 15 operations and time complexity is O(15) = O(1)

// 2. drop the constants
// 3. drop the lower value terms(in expression)


//** what is space complexity?
// how much memory is required to run the algorithm(auxiliary space+input space)
//1. auxiliary space is the extra space required by the algorithm
//2. input space is the space required by the input
//3. total space is the sum of auxiliary space and input space
// **example of space complexity
// function sum(int a, int b) {
//     int c = a + b;
//     return c;
// } auxiliary space is 4 bytes for variable c and input space is 8 bytes for variables a and b and total space is 12 bytes and space complexity is O(12) = O(1)
//** disclaimer: never change the input space or input data or manipulate the input data, because in software engineering we are not allowed to change the input data or input space or manipulate the input data and we are only allowed to change the auxiliary space


//** 1s ~ (10^9 or 10^8) most of the time it is 10^8 because of the time taken by the compiler to compile the code on the online judge platform.
// 2s ~ (2 * 10^9 or 2 * 10^8)



// The constant 100 means 10^2, 1000 means 10^3, 10000 means 10^4.