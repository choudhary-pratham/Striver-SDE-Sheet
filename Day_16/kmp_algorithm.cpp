vector<int>generate_pi(string p)
{
    vector<int>pi(p.size(),0);
    for(int i=1;i<p.size();i++)
    {
        int j = pi[i-1];
        while(j>0 && p[i] != p[j])
        {
            j = pi[j-1];
        }
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}
bool findPattern(string p, string s)
{
    // Write your code here.
    vector<int>pi = generate_pi(p);
    int i = 0, j = 0;
    while(i<s.size())
    {
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else
        {
            if(j!=0) j = pi[j-1];
            else {
                i++;
            }
        }
        if(j == p.size()) {
//             cout<<i-p.size()<<endl; //to print the position.
            return true;
        }
    }
    return false;
}