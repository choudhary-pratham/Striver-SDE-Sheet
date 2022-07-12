#include<algorithm>
struct Node{
    Node* links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
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
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->set(bit,new Node());
            }
            node = node->get(bit);
        }
    }
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
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    int q = queries.size();
    int n = arr.size();
    vector<int>ans(q,0);
    Trie* trie = new Trie();
    sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>>oq;
    for(int i=0;i<q;i++)
    {
        oq.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(oq.begin(),oq.end());
    int ind = 0;
    for(int i=0;i<q;i++)
    {
        int ai = oq[i].first;
        int xi = oq[i].second.first;
        int Qind = oq[i].second.second;
        while(ind<n && arr[ind]<=ai)
        {
            trie->insert(arr[ind]);
            ind++;
        }
        if(ind == 0) ans[Qind] = -1;
        else ans[Qind] = trie->getMax(xi);
    }
    return ans;
}