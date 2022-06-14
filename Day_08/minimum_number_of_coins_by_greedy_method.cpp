int findMinimumCoins(int amount) 
{
    // Write your code here
	int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int i=sizeof(arr)/sizeof(arr[0])-1,count=0;
	while(i>=0)
	{
		while(arr[i]<=amount)
		{
			amount = amount-arr[i];
			count++;
		}
		i--;
	}
	return count;
}
