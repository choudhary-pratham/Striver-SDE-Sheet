string writeAsYouSpeak(int n) 
{
	// Write your code here.
    if(n == 1) return "1";
    if(n == 2) return "11";
    string ans = "11";
    for(int i=3;i<=n;i++)
    {
        int c = 1;
        string temp="";
        ans += '@';
        for(int j=1;j<ans.size();j++)
        {
            if(ans[j] == ans[j-1])c++;
            else
            {
                temp += to_string(c);
                temp += ans[j-1];
                c=1;
            }
        }
        ans = temp;
    }
    return ans;
}