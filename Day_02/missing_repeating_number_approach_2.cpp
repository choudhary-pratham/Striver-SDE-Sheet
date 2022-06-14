int f(int n)
{
    int pos;
    for(int i=0;i<64;i++)
    {
        if(((n>>i)&1)==1) pos=i;
    }
    return pos;
}
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair<int,int>ans;
    int s0=0;
    
    for(int i=0;i<n;i++)
    {
        s0^=arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        s0^=i;
    }
    int x=0,y=0;
    int set_bit = f(s0);
//     cout<<set_bit_position<<endl;
    for(int i=0;i<n;i++)
    {
        if((arr[i]>>set_bit)&1==1)
        {
            x^=arr[i];
        }
        else {
        y^=arr[i];
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if((i>>set_bit)&1==1)
        {
        	x^=i;
        }
        else {
            y^=i;
        }
    }
    bool miss = true;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == x) {miss=false;break;}
    }
    if(miss)
    {
        ans.first = x;
    	ans.second = y;
    }
    else
    {
        ans.first = y;
    	ans.second = x;
    }
    return ans;
}