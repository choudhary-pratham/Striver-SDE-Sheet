#include<algorithm>
string reverseString(string str)
{
    // Write your code here.
    reverse(str.begin(),str.end());
    int i = 0,j = 0;
    while(i<str.size())
    {
        while(i<str.size() && str[i] == ' ')i++;
        j = i+1;
        while(j<str.size() && str[j] != ' ')j++;
        reverse(str.begin()+i,str.begin()+j);
        i=j;
    }
    i = 0;
    while(i<str.size() && str[i] == ' ')i++;
    str = str.substr(i,str.size());
    return str;
}