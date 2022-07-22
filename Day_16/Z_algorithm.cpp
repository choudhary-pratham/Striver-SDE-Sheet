vector<int>computeZ(string tot,int len)
{
    int left = 0;
    int right = 0;
    vector<int>Z(len);
    Z[0] = 0;
    for(int k = 1;k<len;k++)
    {
        if(k > right)
        {
            left = right = k;
            while(right < len && tot[right] == tot[right-left])
            {
                right++;
            }
            Z[k] = right-left;
            right--;
        }
        else
        {
            int k1 = k - left;
            if(Z[k1] < right-k+1) Z[k] = Z[k1];
            else
            {
                left = k;
                while(right < len && tot[right] == tot[right-left])
            {
                right++;
            }
            Z[k] = right-left;
            right--;
            }
        }
    }
    return Z;
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string tot = p + '$' + s;
    int len = tot.size();
    int ans = 0;
    vector<int>z(len);
    z = computeZ(tot,len);
    for(int i=0;i<len;i++)
    {
        if(z[i] == m) ans++;
    }
    return ans;
}