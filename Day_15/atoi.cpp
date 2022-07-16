int atoi(string str) {
    // Write your code here.
    int ans = 0;
    int n = str.size();
    for(int i=0;i<n;i++)
    {
        ans = ((str[i] - '0' >= 0) && (str[i] - '0'<=9))?ans * 10 +(str[i] - '0'):ans;
    }
    if(str[0] == '-') ans = ans*-1;
    return ans;
}