bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n = str1.size(),m = str2.size();
    if(n!=m) return 0;
    vector<int>freq(26,0);
    for(int i=0;i<n;i++)
    {
        freq[str1[i]-'a']++;
    }
    for(int j=0;j<n;j++)
    {
        if(freq[str2[j]-'a'] == 0) return 0;
    }
    return 1;
}