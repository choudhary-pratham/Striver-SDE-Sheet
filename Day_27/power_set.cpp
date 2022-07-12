vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>>ans;
    int n = v.size();
    int last = (1<<n);
    for(int num = 0;num<last;num++)
    {
        vector<int>sub;
        for(int i=0;i<n;i++)
        {
            if((num &(1<<i)) != 0)
            {
                sub.push_back(v[i]);
            }
        }
        ans.push_back(sub);
    }
    return ans;
}