class Solution
{
    public:
    void merge(int arr[],int l,int mid,int r)
    {
        int temp[r-l+1];
        int i=l;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=r)
            arr[i]<arr[j]?temp[k++]=arr[i++]:temp[k++]=arr[j++];
        if(i==mid+1)
            while(j<=r)
               temp[k++]=arr[j++];
        else
            while(i<=mid)
               temp[k++]=arr[i++];
        for(int x=l,y=0;x<=r;x++,y++)
            arr[x]=temp[y];
    }
    
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
            return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
