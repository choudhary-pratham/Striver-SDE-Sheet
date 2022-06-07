int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int count=0,element=0;
    for(int i=0;i<n;i++)
    {
        if(count==0) {element = arr[i];}
        if(arr[i] == element) {count++;}
        else {count--;}
    }
     int cnt=0;  

   for(int i=0;i<n;i++)

   {

       if(arr[i]==element)

           cnt++;

   }

   

   if(cnt>n/2)

       return element;

   return -1;
}