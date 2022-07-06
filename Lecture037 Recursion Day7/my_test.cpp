//** Subset
class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int> output,vector<int> nums){
        
        if(nums.size() == 0){
            ans.push_back(output);
            return;
        }
        // choice 1
        vector<int> op1 = output;
        // choice 2
        vector<int> op2 = output;
        op2.push_back(nums[0]);
        
        nums.erase(nums.begin()+0);
        solve(ans,op1,nums);  
        solve(ans,op2,nums);    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans,output,nums);
        return ans;
    }
};


//** permutationWithSpaces 
class Solution{
public:
    void solve(vector<string>& ans,string output,string s){
        if(s.size() == 0){
            ans.push_back(output);
            return;
        }
        
        
        string op2 = output;
        string op1 = output;

        // choice 1
        op1.push_back(' ');
        op1.push_back(s[0]);
        // choice 2
        op2.push_back(s[0]);
        
        
        s.erase(s.begin()+0);
        solve(ans,op1,s);
        solve(ans,op2,s);
    }
    vector<string> permutationWithSpaces(string S){
        vector<string> ans;
        string output;

        output.push_back(S[0]);
        S.erase(S.begin()+0);
        
        solve(ans,output,S);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
}


//** permutation
class Solution {
private:
    void solve(vector<vector<int>>&ans,int ind,vector<int> nums,vector<int> output){
        
       if(ind>=nums.size())
       {
           // ans.push_back(output);
            ans.push_back(nums);
           return;
       }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            // output=nums;
            solve(ans,ind+1,nums,output);
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int ind = 0;
        solve(ans,ind,nums,output);
        return ans;
    }
};


//** letterCasePermutation
class Solution {
public:
    void solve(vector<string>& ans,string output,string s){
        if(s.size() == 0){
            ans.push_back(output);
            return;
        }
        
        // ex
        string op2 = output;
        string op1 = output; 
        string op3 = output;

        if((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))         {      
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin()+0);
            solve(ans,op1,s);
            solve(ans,op2,s);
        }else{
            op3.push_back(s[0]);
            s.erase(s.begin()+0);
            solve(ans,op3,s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string output;
        solve(ans,output,s);
        return ans;
    }
};