class Node{
    public:
    char data;
    Node* children[26];
    bool terminal;
    Node(char data){
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        
        terminal = false;
    }
};