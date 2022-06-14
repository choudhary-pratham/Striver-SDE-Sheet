int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int ans = 1;
    while(n>0)
    {
        if(n%2==0)
        {
            x = (x*1LL*x)%m;
            n/=2;
        }
        else
        {
            ans=(ans*1LL*x)%m;
            n--;
        }
    }
    return ans;
}