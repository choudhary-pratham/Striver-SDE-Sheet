#include<vector>
string longestPalinSubstring(string str)
{
    // Write your code here.
    int n = str.size();
    int length = 0;
    string ans = "";
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=i;j--)
            {
                if(i == j) dp[i][j] = 1;
                else if((j-i+1) == 2 && str[i] == str[j]) dp[i][j] = 1;
                else if(str[i] == str[j] && dp[i+1][j-1] == 1) dp[i][j] = 1;
                if(dp[i][j] == 1)
                {
                    if(length <= (j-i+1))
                    {
                        length = j-i+1;
                        ans = str.substr(i,length);
                    }
                }
        }
    }
    return ans;
    
}