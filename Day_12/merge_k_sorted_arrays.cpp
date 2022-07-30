#include<queue>
struct values{
    int val,row,column;
    values(int val,int row,int column)
    {
        this->val = val;
        this->row = row;
        this->column = column;
    }
};
struct comp{
    bool operator()(values a,values b){
        return a.val > b.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int>ans;
    priority_queue<values,vector<values>,comp>pq;
    for(int i=0;i<kArrays.size();i++)  pq.push(values(kArrays[i][0],i,0));
    while(!pq.empty())
    {
        int val = pq.top().val;
        int row = pq.top().row;
        int column = pq.top().column;
        ans.push_back(val);
        pq.pop();
        if(column+1<kArrays[row].size()) pq.push(values(kArrays[row][column+1],row,column+1));
    }
    return ans;
}
