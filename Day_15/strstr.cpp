// strstr function returns true if the string s2 is present in s1
bool mystrstr(string s1,string s2)
{
    //write your code here
    int n = s1.size(),m = s2.size(),i=0,j=0;
    while(i<n && j<m)
    {
        if(s1[i] != s2[j]){
            if(j!=0) return false;
            i++;
        } 
        else{
            i++;
            j++;
        }
    }
    return (j==m);
}
