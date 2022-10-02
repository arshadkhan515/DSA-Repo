// Find the Winner of the Circular Game  
// obsureved this question is nth answer debend on n-1th answer and 
// so we can use recursion to solve this problem

class Solution {
public:
    int solve(int n,int k){
        if(n == 1)
            return 0;
        // current ans is depend on prev ans with diffrence of k
        // and we use mod to make it in range of 0 to n-1
        return (solve(n-1,k)+k) % n;
    }
    int findTheWinner(int n, int k) {
        // and we add 1 because we have to find the winner of the circular game 1 to n 
        // and this funtion return the winner of the circular game 0 to n-1
        // and need to add 1 to make it in range of 1 to n
        return solve(n,k) +1;
    }
};