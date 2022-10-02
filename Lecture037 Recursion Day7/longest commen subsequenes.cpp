// Longest Common Subsequence
// is a classic problem in Computer Science. Given two strings, find the longest
// common subsequence. For example, given the strings “ABAZDC” and “BACBAD”, the
// longest common subsequence is “ABAD”.

// this Approach use include and exclude method
// step 1: i and j are at the first index of both string
// step 2: if both char are same then include it in the answer and move both i and j
// step 3: if both char are not same then exclude one of them and move i or j
// step 4: if both char are not same then exclude both of them and move i and j
// step 5: return the max of all the above 3 cases

class Solution {
public:





    int solve(string t1,string t2,int i,int j){
        if(i == t1.size() || j == t2.size()){
            return 0;
        }
        // include
        int inc = 0;
        if(t1[i] == t2[j]){
            inc = 1+solve(t1,t2,i+1,j+1);
        }
        // exclude
        int exc = 0;
        exc = max(solve(t1,t2,i+1,j),solve(t1,t2,i,j+1));
        
        return max(inc,exc);
        
    }
    int longestCommonSubsequence(string t1, string t2) {
        int i = 0;
        int j = 0;
        return solve(t1,t2,i,j);
    }
};
