#include<unordered_map>
class LRUCache
{
public:
    class node{
        public:
        int key;
        int value;
        node* next;
        node* prev;
        node(int key_,int value_)
        {
            key = key_;
            value = value_;
        }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>m;
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    void addNode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    int get(int key)
    {
        if(m.find(key) != m.end())
        {
            node* resnode = m[key];
            int val = resnode->value;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(m.find(key)!=m.end())
        {
            node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        m[key] = head->next;
    }
};
