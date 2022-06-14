int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    
    int platforms = 1,result = 1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            platforms++;
            i++;
        }
        else if(at[i]>dt[j])
        {
            platforms--;
            j++;
        }
        result = max(result,platforms);
    }
    return result;
}