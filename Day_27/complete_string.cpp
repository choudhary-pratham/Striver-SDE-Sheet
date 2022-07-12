struct Node{
    Node* links[26];
    bool flag = false;
    
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
    
    void setEnd()
    {
        flag = true;
    }
    
    bool isEnd()
    {
        return flag == true;
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
    
    void insert(string word)
    {
        Node * node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->set(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    } 
    
    bool checkPrefixExist(string word)
    {
        Node * node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if(node->isEnd() == false) return false; 
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie* trie = new Trie();
    for(auto &it:a)
    {
        trie->insert(it);
    }
    string longest_string = "";
    for(auto &it:a)
    {
        if(trie->checkPrefixExist(it) == true)
        {
            if(it.size() > longest_string.size()) longest_string = it;
            else if(it.size() == longest_string.size() && it<longest_string) longest_string = it;
        }
    }
    if(longest_string == "") return "None";
    else return longest_string;
}