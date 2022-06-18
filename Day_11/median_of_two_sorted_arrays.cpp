double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    if(a.size()>b.size()) return median(b,a);
    int n = a.size();
    int m = b.size();
    int low = 0,high = n;
    while(low<=high)
    {
        int cut1 = (low+high)/2;
        int cut2 = ((n+m+1)/2) - cut1;
        
        int l1 = (cut1 == 0)?-1e9:a[cut1-1];
        int l2 = (cut2 == 0)?-1e9:b[cut2-1];
        int r1 = (cut1 == n)?1e9:a[cut1];
        int r2 = (cut2 == m)?1e9:b[cut2];
        
        if(l1<=r2 && l2<=r1)
        {
            if((n+m)%2 == 0)
            {
                return (double)((double)max(l1,l2)+(double)(double)min(r1,r2))/2.0;
            }
            else 
            {
                return (double)max(l1,l2);
            }
        }
        else if(l1>r2) {
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }
    return 0.0;
}
