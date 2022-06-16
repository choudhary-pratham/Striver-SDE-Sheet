void f(int ind,string &s,vector<string>&dictionary,string word,vector<string>&ans)
{
    if(ind == s.size())
    {
        word = word.substr(0,word.size()-1);
        ans.push_back(word);
        return;
    }
    string sub = "";
    for(int partition = ind;partition<s.size();partition++)
    {
        sub+=s[partition];
        if(find(dictionary.begin(),dictionary.end(),sub)!=dictionary.end())
        {
            f(partition+1,s,dictionary,word+sub+" ",ans);
        }
    }
}


vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string>ans;
    f(0,s,dictionary,"",ans);
    return ans;
}