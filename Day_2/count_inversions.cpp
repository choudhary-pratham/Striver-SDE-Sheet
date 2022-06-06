void merge(long long *arr,long long *temp,int low,int mid,int high,long long &inv)
{
    int i = low,j = mid,k = low;
    while(i<=mid-1 && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else 
        {
            temp[k++] = arr[j++];
            inv += (mid-i); 
        }
    }
    while(i<=mid-1)
    {
        temp[k++]= arr[i++];
    }
    while(j<=high)
    {
        temp[k++] = arr[j++];
    }
    for(int i=low;i<=high;i++)
    {
        arr[i] = temp[i];
    }
}
void mergesort(long long *arr,long long *temp,int low,int high,long long &inv)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(arr,temp,low,mid,inv);
        mergesort(arr,temp,mid+1,high,inv);
        merge(arr,temp,low,mid+1,high,inv);
    }
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long inv = 0;
    long long temp[n];
     mergesort(arr,temp,0,n-1,inv);
    return inv;
}