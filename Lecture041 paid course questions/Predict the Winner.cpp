// Predict the Winner 
// Predict the winner of an array of integers, where each player takes a turn at removing an integer from either end of the array. The player with the highest score wins.
// Example 1:
// Input: [1, 5, 2]
// Output: False
// Explanation: Initially, player 1 can choose between 1 and 2. If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. Hence, player 1 will never be the winner and you need to return False.
// Example 2:
// Input: [1, 5, 233, 7]
// Output: True



// Approach of this problem is to use only recursion.
// We will use recursion to find the maximum score of the player who is playing first.
//is the maximum of the following two cases:


// 1. If the player chooses the leftmost element, the score will be equal to this element plus the minimum of the following two scores:
// a. The score obtained by the opponent by choosing from the remaining elements except the leftmost.
// b. The score obtained by the opponent by choosing from the remaining elements except the rightmost.
// and plus the minimum of the following two scores: 

class Solution {
public:
    int solve(vector<int>& nums,int i,int j){
        if(i>j)
            return 0;
        if(i==j)
            return nums[i];
        
        
        int op1 = nums[i] + min(solve(nums,i+2,j),solve(nums,i+1,j-1)); 
        int op2 = nums[j] + min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        
        
        return max(op1,op2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        // find the maximum score of the player who is playing first.
        int p1_score = solve(nums,0,nums.size()-1);
        int p2_score = 0;
        // find the total score of the game
        for(auto i:nums){
            p2_score += i;
        }
        // and subtract the score of the first player from second player
        // and find the total score of player 2
        p2_score -= p1_score;
        // if the score of player 1 is greater than or equal to player 2 then player 1 will win 
        return p1_score >= p2_score;
    }
};