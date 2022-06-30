#include<queue>
#include<map>

struct node{
    int height;
    int leftIndex;
    int rightIndex;
    node(int h,int l,int r){
        height = h;
        leftIndex = l;
        rightIndex = r;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int N){
	// Write your code here.
    queue<node*>q;
    map<int,int>inmap;
    node* init = new node(0,0,N-1);
    q.push(init);
    for(int i=0;i<N;i++)
    {
        inmap[inorder[i]] = i;
    }
    int maxHeight = 0;
    for(int i=0;i<N;i++)
    {
        int inroot = inmap[levelorder[i]];
        node* now = q.front();
        q.pop();
        if(inroot > now->leftIndex)
        {
            node* newnode = new node(now->height+1,now->leftIndex,inroot-1);
            maxHeight = max(maxHeight,newnode->height);
            q.push(newnode);
        }
        if(inroot < now->rightIndex)
        {
            node* newnode = new node(now->height+1,inroot+1,now->rightIndex);
            maxHeight = max(maxHeight,newnode->height);
            q.push(newnode);
        }
    }
    return maxHeight;
}