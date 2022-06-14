void f(string s, string str,vector<string>&ans,vector<int>&freq)
{
    if(str.size() == s.size())
    {
        ans.push_back(str);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        if(freq[i] == 0)
        {
            freq[i] = 1;
            f(s,str+s[i],ans,freq);
            freq[i] = 0;
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    string str="";
    vector<int>freq(s.size(),0);
    f(s,str,ans,freq);
    return ans;
}