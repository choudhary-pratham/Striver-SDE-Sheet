vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int base = 31;
    int mod = (int)1e9+7;
    int n = str.size();
    int m = pat.size();
    vector<long long>power(n);
    power[0] = 1;
    for(int i=1;i<n;i++)
    {
        power[i] = (power[i-1] * base)%mod;
    }
    vector<long long>h(n+1,0);
    
    for(int i=0;i<n;i++)
    {
        h[i+1] = (h[i] + (str[i] - 'A' + 1)*power[i])%mod;
    }
    long long hashPattern = 0;
    for(int i=0;i<m;i++)
    {
        hashPattern = (hashPattern + (pat[i]-'A'+1)*power[i])%mod;
    }
    vector<int>occurences;
    for(int i=0;i+m-1<n;i++)
    {
        long long curHash = (h[i+m] + mod - h[i])%mod;
        if(curHash == hashPattern *power[i]%mod)
        {
            occurences.push_back(i);
        }
    }
    return occurences;
}
