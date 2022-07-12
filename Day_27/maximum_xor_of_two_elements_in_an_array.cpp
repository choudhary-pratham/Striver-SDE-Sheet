struct Node{
    Node* links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!= NULL);
    }
    
    void set(int bit,Node* node)
    {
        links[bit] = node;
    }
    
    Node* get(int bit)
    {
        return links[bit];
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
    void insert(int num)
    {
        Node* node = root;
        for(int i = 31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->set(bit,new Node());
            }
            node = node->get(bit);
        }
    }
public:
    int getMax(int num)
    {
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie* trie = new Trie();
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        trie->insert(A[i]);
    }
    for(int j = 0;j<A.size();j++)
    {
        ans = max(ans,trie->getMax(A[j]));
    }
    return ans;
}