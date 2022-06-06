/*gap method*/
int FindGap(int gap)
{
    if(gap<=1) return 0;
    return (gap/2 + gap%2);
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    int gap = n+m;
        int i=0,j=0;
        for(gap = FindGap(gap);gap>0;gap = FindGap(gap))
        {
            for( i=0;i+gap<m;i++)
            {
                if(arr1[i] > arr1[i+gap])
                {
                    swap(arr1[i],arr1[i+gap]);
                }
            }
            for(j = (gap>m)?(gap-m):0;i<m && j<n;i++,j++)
            {
                if(arr1[i]>arr2[j])
                {
                    swap(arr1[i],arr2[j]);
                }
            }
            if(j<n)
            {
                for( j=0;j+gap<n;j++)
                {
                    if(arr2[j] > arr2[j+gap])
                    {
                        swap(arr2[j],arr2[j+gap]);
                    }
                }
            }
        }
        int k=0;
        while(i<m+n)
        {
            arr1[i] = arr2[k];
            i++;k++;
        }
    return arr1;
}