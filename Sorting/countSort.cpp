#include<iostream>
#include<climits>
using namespace std;

int minArr(int arr[],int n)
{
    int mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<mn)
            mn=arr[i];
    }
    return mn;
}

int maxArr(int arr[],int n)
{
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>mx)
            mx=arr[i];
    }
    return mx;
}

void countSort(int arr[], int n)
{
    int* temp=new int[n];
    int min=minArr(arr,n);
    int max=maxArr(arr,n);
    if(min>0)
        min=0;
    int range=max-min+1;
    int count[range]={0};
    for(int i=0;i<n;i++)
        count[arr[i]-min]++;
    for(int i=1;i<range;i++)
        count[i]=count[i]+count[i-1];
    for(int i=n-1;i>=0;i--)
        temp[--count[arr[i]-min]]=arr[i];
    for(int i=0;i<n;i++)
        arr[i]=temp[i];
}

int main()
{
    int n;
    cout<<"Enter array Size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    countSort(arr,n);
    cout<<"Array after sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
