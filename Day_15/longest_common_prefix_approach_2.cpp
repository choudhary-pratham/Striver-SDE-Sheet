struct Node
{
    Node* links[26];
    bool flag = false;
    int count_prefix = 0;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void increment_count()
    {
        count_prefix++;
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
class Trie
{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    string insert_and_checkLcp(string &word,int n)
    {
        Node* node = root;
        string ans = "";
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
                node->count_prefix=0;
            }
            node->increment_count();
            if(node->count_prefix == n) {
                ans+=word[i];
            }
            node = node->get(word[i]);
            
        }
        node->setEnd();
        return ans;
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* trie = new Trie();
    string ans="";
    for(auto &it:arr)
    {
        ans = trie->insert_and_checkLcp(it,n);
    }
    return ans;
}


