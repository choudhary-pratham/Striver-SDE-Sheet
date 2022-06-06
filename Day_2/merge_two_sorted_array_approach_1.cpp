vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    int i=0;
    while(i<m)
    {
        if(arr1[i]>arr2[0])
        {
            swap(arr1[i],arr2[0]);
            int j=1;
            while(j<n)
            {
                if(arr2[j]<arr2[j-1])
                {
                    swap(arr2[j],arr2[j-1]);
                }
                j++;
            }
        }
        i++;
    }
    int j=0;
	while(i<m+n)
    {
        arr1[i] = arr2[j];
        i++;j++;
    }
    return arr1;
}