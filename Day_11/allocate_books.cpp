bool isAllocationPossible(vector<int>&time,int m,long long  mid,int n)
{
    long long  day_count = 1,time_count = 0;
    for(int i=0;i<time.size();i++)
    {
        if(time[i]>mid) return false;
        if(time_count+time[i] > mid)
        {
            day_count += 1;
            time_count = time[i];
        }
        else
        {
            time_count += time[i];
        }
    }
    if(day_count > n) return false;
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long ans = -1;
    long long  low = 0;
    long long high = 0;
    for(int i=0;i<m;i++)
    {
        high += time[i];
    }
    while(low<=high)
    {
        long long  mid = (low+high)>>1;
        if(isAllocationPossible(time,m,mid,n))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    // low can also be returned as the final answer
    return ans;
}