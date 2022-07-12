struct Node
{
    Node* links[26];
    
    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    
    void set(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};

class Trie{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    
    int insert(string word)
    {
        int count = 0;
        for(int i=0;i<word.size();i++)
        {
            Node* node = root;
             for(int j=i;j<word.size();j++)
            {
                if(!node->containsKey(word[j]))
                {
                    count++;
                    node->set(word[j],new Node());
                }
                node = node->get(word[j]);
             }
        }
        return count;
    }
};

int distinctSubstring(string &word) {
    //  Write your code here.
    Trie* trie = new Trie();
    int count = trie->insert(word);
    return count;
}
