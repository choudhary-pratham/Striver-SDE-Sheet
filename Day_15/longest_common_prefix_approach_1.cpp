#include<algorithm>
string longestCommonPrefix(vector<string> &arr, int n)
{
    sort(arr.begin(),arr.end());
    string smallest = arr[0];
    string largest = arr[n-1];
    string ans = "";
    for(int i=0;i<smallest.size();i++)
    {
        if(smallest[i] == largest[i])
        {
            ans += smallest[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}


