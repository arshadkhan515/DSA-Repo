#include <bits/stdc++.h>
using namespace std;
#include "./TrieNode.cpp"

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    // Insertion
    // How to insert a word in a trie
    // 1. Start from the root node
    // 2. Find the first character of the word in the children of the root node
    // 3. If the character is not found, create a new node with the character
    // 4. Repeat steps 2 and 3 for the next character of the word until the end of the word

    // Note : every character is mapped to a array of size 26 (for 26 alphabets) and the index of the array is the ascii value of the character - 97 (for a) and so on and so forth

    void print()
    {
        if (root == NULL)
        {
            return;
        }
        cout << "dsfds" << endl;
        for (int i = 0; i < 26 && root->children[i] != NULL; i++)
        {
            cout << root->children[i]->data << endl;
        }
    }

    bool search(Node *root, string s)
    {
        // if (s.size() == 0)
        // {
        //     return root->terminal;
        // }
        // int index = s[0] - 'A';
        // Node *child;
        // if (root->children[index] != NULL && root->children[index]->data == s[0])
        // {
        //     child = root->children[index];
        // }
        // else
        // {
        //     return false;
        // }
        // return search(child, s.substr(1));
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'A';
            if (root->children[index] != NULL)
            {
                root = root->children[index];
            }
            else
            {
                return false;
            }
        }
        if (root->terminal)
            return true;
        else
            return false;
    }

    void remove(Node *root, string s)
    {
        if (s.size() == 0)
        {
            if (root->terminal == true)
            {
                root->terminal = false;
            }
            return;
        }
        int index = s[0] - 'A';
        Node *child;
        if (root->children[index] != NULL && root->children[index]->data == s[0])
        {
            child = root->children[index];
        }

        remove(child, s.substr(1));
    }

    void insert(Node *root, string val)
    {
        if (val.size() == 0)
        {
            root->terminal = true;
            return;
        }
        int index = val[0] - 'A';
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
        insert(child, val.substr(1));
    }
    
    bool IsChildrenPresent(Node *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return true;
            }
        }
        return false;
    }
    Node *removeWithNode(Node *root, string s)
    {
        if (s.size() == 0)
        {
            if (root->terminal)
            {
                if (IsChildrenPresent(root))
                {
                    return root;
                }
                return NULL;
            }
        }

        int ind = s[0] - 'A';
        Node *child = root->children[ind];

        if (child == NULL)
        {
            return root;
        }
        else
        {
            root->children[ind] = removeWithNode(child, s.substr(1));
        }
        if (IsChildrenPresent(root) && root->terminal == false)
        {
            return NULL;
        }
        return root;
    }

    void insertWord(string s)
    {
        insert(root, s);
    }

    void searchWord(string s)
    {
        if (search(root, s))
        {
            cout << "Present" << endl;
        }
        else
        {
            cout << "Not Present" << endl;
        }
    }

    void removeWord(string s)
    {
        if (search(root, s))
        {
            // remove(root, s);
            removeWithNode(root, s);
        }
        else
        {
            cout << "Noting For Deletion" << endl;
        }
    }
};
int main()
{
    Trie *root = new Trie();
    root->insertWord("abcd");
    // root->print();
    root->searchWord("a");
    root->searchWord("abcd");
    root->removeWord("abcd");
    root->searchWord("abcd");
    // root->removeWord("abcd");
    return 0;
}