class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)
            return;
        int pvt=partition(arr,low,high);
        quickSort(arr,low,pvt-1);
        quickSort(arr,pvt+1,high);
    }

    void swap(int arr[],int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    
    int partition (int arr[], int low, int high)
    {
       int mid=low;
       int pivot=arr[mid];
       int i=low;
       int j=high;
       while(i<j)
       {
           while(arr[i]<=pivot)
               i++;
            while(arr[j]>pivot)
               j--;
            if(i<j)
                swap(arr,i,j);
       }
       swap(arr,j,mid);
       return j;
    }
};
