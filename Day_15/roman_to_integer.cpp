#include<map>
int romanToInt(string str) {
    // Write your code here
    map<char,int>mpp;
    mpp['I'] = 1;
    mpp['V'] = 5;
    mpp['X'] = 10;
    mpp['L'] = 50;
    mpp['C'] = 100;
    mpp['D'] = 500;
    mpp['M'] = 1000;
    int ans = mpp[str[str.size()-1]];
    for(int i = str.size()-2;i>=0;i--)
    {
        if(mpp[str[i]] >= mpp[str[i+1]]) ans += mpp[str[i]];
        else  ans -= mpp[str[i]];
    }
    return ans;
}
