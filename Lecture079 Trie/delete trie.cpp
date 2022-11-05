//**problem https://www.codingninjas.com/codestudio/problems/trie-delete-operation_1062663?leftPanelTab=1
//**solution https://www.codingninjas.com/codestudio/problems/trie-delete-operation_1062663?leftPanelTab=2
//** Approach 1: Recursion
// in this approach we will use recursion to delete the node
// we will first check if the node is terminal or not
// if it is terminal then we will make it non terminal
// if it is not terminal then we will check if it has any children or not
// if it has children then we will return root
// if it does not have any children then we will delete the node and return NULL
// Time Complexity: O(s.length())
// Space Complexity: O(s.length())
#include <bits/stdc++.h>

/*class TrieNode { //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};*/

#include <bits/stdc++.h>
bool IsChildrenPresent(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            return true;
            ;
        }
    }
    return false;
}
TrieNode *removeWithNode(TrieNode *root, string s)
{
    if (!root)
        return root;

    if (s.size() == 0)
    {
        if (root->isEnd)
        {
            root->isEnd = false;
            if (IsChildrenPresent(root))
            {
                return root;
            }
            return NULL;
        }
    }

    int ind = s[0] - 'a';
    TrieNode *child = root->children[ind];

    if (!child)
        return root;
    else
        root->children[ind] = removeWithNode(child, s.substr(1));

    if (IsChildrenPresent(root) && root->isEnd == false)
    {
        return NULL;
    }
    return root;
}

TrieNode *solution::deleteWord(TrieNode *root, string word)
{
    return removeWithNode(root, word);
}