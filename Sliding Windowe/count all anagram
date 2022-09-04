class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> M;
	    vector<int> ans;
	    for(auto i:p){
	        M[i]++;
	    }
	    int count = M.size();
	    int j = 0;
	    int i = 0;
	    int n = s.size(),k=p.size();
	    
	    while(j<n){
	        if(M.find(s[j]) != M.end()){
	            M[s[j]]--;
	            if(M[s[j]] == 0){
	                count--;
	            }
	        }
	        
	        if(j-i+1 < k){
	            j++;
	        }else if(j-i+1 == k){
	            if(count == 0){
	                // ans++;
                    ans.push_back(i);
	            }
    	         if(M.find(s[i]) != M.end()){
    	            M[s[i]]++;
    	            if(M[s[i]] == 1){
    	                count++;
    	            }
    	        }
    	        i++;
    	        j++;
	        }
	        
	    }
        return ans;
    }
};