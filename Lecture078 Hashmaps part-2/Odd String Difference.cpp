// question of leetcode 2451
// https://leetcode.com/problems/odd-string-difference/
class Solution {
public:
    string oddString(vector<string>& words) {
          int n = words.size(); int slenght = words[0].size();
          map<vector<int>,pair<string,int>> M;
         
          for(int i = 0;i<n;i++){
              vector<int> temp;
              for(int j = 0;j<slenght-1;j++){
                  temp.push_back(words[i][j+1]-words[i][j]);
              }
              M[temp].first = words[i];
              M[temp].second++;
          }
        
        for(auto i:M){
            if(i.second.second == 1){
                return i.second.first;
            }
        }
        return " ";
    }
};