double multiply(double num,int n)
{
    double ans=1.00;
    for(int i=1;i<=n;i++)
    {
        ans = ans*(double)num;
    }
    return ans;
}

double findNthRootOfM(int n, long long m) {
    // Write your code here.
    double low = 1.00;
    double high = m;
    double eps = 1e-7;
    while((high-low)>eps)
    {
        double mid = (low+high)/2.00;
        if(multiply(mid,n) < (double)m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}
