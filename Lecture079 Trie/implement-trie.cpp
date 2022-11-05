/*
    Time Complexity : O(N*W) (insert - O(W), search - O(W), startsWith - O(W))
    Where N is the number of queries and W is the average length of words.

    Space Complexity : O(N*W)
    Where N is the number of words inserted and W is the average length of words.
*/

// Recursive implementation
class Node
{
public:
    char data;
    Node *children[26];
    bool terminal;
    Node(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        terminal = false;
    }
};

class Trie
{

public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insertWord(Node *root, string val)
    {
        if (val.size() == 0)
        {
            root->terminal = true;
            return;
        }
        int index = val[0] - 'a';
        Node *child;

        if (root->children[index] != NULL && root->children[index]->data == val[0])
        {
            child = root->children[index];
        }
        else
        {
            Node *newNode = new Node(val[0]);
            root->children[index] = newNode;
            child = newNode;
        }
        insertWord(child, val.substr(1));
    }
    bool searchWord(Node *root, string s)
    {
        if (s.size() == 0)
        {
            return root->terminal;
        }
        int index = s[0] - 'a';
        Node *child;
        if (root->children[index] != NULL && root->children[index]->data == s[0])
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchWord(child, s.substr(1));
    }
    bool prefixWord(Node *root, string s)
    {
        if (s.size() == 0)
        {
            return true;
        }
        int index = s[0] - 'a';
        Node *child;
        if (root->children[index] != NULL && root->children[index]->data == s[0])
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return prefixWord(child, s.substr(1));
    }
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        insertWord(root, word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return searchWord(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return prefixWord(root, prefix);
    }
};

//********************************************************************//
// iterative solution
class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie
{
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *tem = root;
        for (auto x : word)
        {
            if (!tem->child[x - 'a'])
                tem->child[x - 'a'] = new TrieNode();
            tem = tem->child[x - 'a'];
        }
        tem->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *tem = root;
        for (auto x : word)
        {
            if (!tem->child[x - 'a'])
                return false;
            tem = tem->child[x - 'a'];
        }
        return tem->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *tem = root;
        for (auto x : prefix)
        {
            if (!tem->child[x - 'a'])
                return false;
            tem = tem->child[x - 'a'];
        }
        return true;
    }
};