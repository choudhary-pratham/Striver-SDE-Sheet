#include<vector>
#include<algorithm>
vector<int>find_lps(string new_string)
{
    vector<int>lps(new_string.size(),0);
    for(int i = 1;i<new_string.size();i++)
    {
        int j = lps[i-1];
        while(j>0 && new_string[i] != new_string[j]) j = lps[j-1];
        if(new_string[i] == new_string[j]) j++;
        lps[i] = j;
    }
    return lps;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
    string revstr = str;
    reverse(revstr.begin(),revstr.end());
    string new_string = str + '$' + revstr;
	vector<int>lps = find_lps(new_string);
    return str.size() - lps[new_string.size()-1];
}
