
// key pad problem using recursion 
// we have to print all the possible words that can be formed from the given number
// for example if the number is 23 then the possible words are ad,ae,af,bd,be,bf,cd,ce,cf
// because 23 is the combination of a,b,c and d,e,f

// we are use the recursion to solve this problem exclude and include method
class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};