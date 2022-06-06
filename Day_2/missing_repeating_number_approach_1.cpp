pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair<int,int>ans;
    long long  s = (n*1LL*(n+1)*1LL)/2LL;
    long long  s2 = (n*1LL*(n+1)*1LL*(2*n+1))/6LL;
    long long  s0=0,s1 =0;
    for(int i=0;i<n;i++)
    {
        s0+=arr[i];
        s1+=(arr[i]*1LL*arr[i]);
    }
    long long  a = (s-s0);//x-y
    long long  b = (s2 - s1);//x2-y2
    b = b/a;//x+y
    int x = (int)((a+b)/2ll);
    int y = (int)((b-a)/2ll);
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
