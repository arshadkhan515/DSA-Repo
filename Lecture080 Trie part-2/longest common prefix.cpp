//problem : https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// solution :https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=2&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// what is difference between prefix and suffix
// if we have a string "abc" then prefix is "a" "ab" "abc"  
// suffix is "abc" "bc" "c"  // reverse of prefix


// Approach 1 : Brute force is Iterative Approach
// In this approach we will take first string as prefix and then we will check if all other string have this prefix or not
// time complexity is O(n*m) where n is number of string and m is length of string
// space complexity is O(1)
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
    for(int i=0;i<arr[0].size();i++){
        string temp1 = arr[0];
        for(int j=1;j<n;j++){
            string temp2 = arr[j];
            if(temp2[i] != temp1[i]){
                return ans;
            }
        }
        ans.push_back(temp1[i]);
    }
    return ans;
}





// Approach 2 : Trie
// In this approach we will insert all the string in trie and then we will check if all the string have same prefix or not
// time complexity is O(n*m) where n is number of string and m is length of string
// space complexity is O(n*m) where n is number of string and m is length of string
class Node{
    public:
    char data;
    Node* children[26];
    bool terminal;
    int childcount;
    Node(char data){
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childcount = 0;
        terminal = false;
    }
};
class Trie {

    public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insertWord(Node *root, string val)
    {
        for(int i = 0;i<val.size();i++){
            int index = val[i]-'a';
            if(root->children[index] != NULL){
                root = root->children[index];
            }else{
                Node* newNode = new Node(val[i]);
                root->children[index] = newNode;
                root->childcount++;
                root = newNode;
            }
        }
        root->terminal = true;
    }
    void insert(string word) {
        insertWord(root,word);
    }

    void prefix(string& ans,string ch) {

        for(int i = 0;i<ch.size();i++){
            int index = ch[i] - 'a';
            if(root->children[index] != NULL && root->childcount == 1){
                ans.push_back(ch[i]);
                root = root->children[index];
            }else{
                break;
            }
            
            if(root->terminal){
                break;
            }
        }
    }
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
    Trie* root = new Trie();
    for(auto x:arr){
        root->insert(x);
    }
    string take = arr[0];
    root->prefix(ans,take);
    return ans;
}