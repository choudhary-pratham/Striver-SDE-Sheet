#include<unordered_map>
struct Node
{
    int key,value,freq;
    Node *next;
    Node *prev;
    Node(int key_,int value_)
    {
        key = key_;
        value = value_;
        freq = 1;
    }
};

struct List
{
    Node* head;
    Node* tail;
    int size;
    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addnode(Node* node)
    {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    void deletenode(Node* node)
    {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache
{
    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqlistmap;
    int curSize;
    int minFreq;
    int maxSize;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        maxSize = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    void updateFreqList(Node* node)
    {
        keyNode.erase(node->key);
        freqlistmap[node->freq]->deletenode(node);
        if(node->freq == minFreq && freqlistmap[node->freq]->size == 0)
        {
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqlistmap.find(node->freq + 1) != freqlistmap.end())
        {
            nextHigherFreqList = freqlistmap[node->freq + 1];
        }
        node->freq += 1;
        nextHigherFreqList->addnode(node);
        freqlistmap[node->freq] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key)!=keyNode.end())
        {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxSize == 0) return;
        if(keyNode.find(key)!=keyNode.end())
        {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else{
            if(curSize == maxSize)
            {
                List* list = freqlistmap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqlistmap[minFreq]->deletenode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            
            List* listfreq = new List();
            if(freqlistmap.find(minFreq) != freqlistmap.end())
            {
                listfreq = freqlistmap[minFreq];
            }
            Node* node = new Node(key,value);
            listfreq->addnode(node);
            keyNode[key] = node;
            freqlistmap[minFreq] = listfreq;
        }
    }
};
