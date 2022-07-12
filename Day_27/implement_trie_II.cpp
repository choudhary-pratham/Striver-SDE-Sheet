struct Node
{
    Node* links[26];
    int countPrefix = 0;
    int countEnd = 0;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    
    void put(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void incrementPrefix()
    {
        countPrefix++;
    }
    
    void incrementEnd()
    {
        countEnd++;
    }
    
    void decrementPrefix()
    {
        countPrefix--;
    }
    
    void decrementEnd()
    {
        countEnd--;
    }
    
    int prefix()
    {
        return countPrefix;
    }
    
    int End()
    {
        return countEnd;
    }
};
class Trie{
    private:
    Node* root;
    public:

    Trie(){
        root = new Node();
        // Write your code here.
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->incrementPrefix();
        }
        node->incrementEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->End();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->prefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->decrementPrefix();
            }
            else
            {
                return;
            }
        }
        node->decrementEnd();
    }
};
