#include<iostream>
#include<climits>
using namespace std;

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

void modifiedCountSort(int arr[],int n,int pos)
{
    int count[10]={0};
    int temp[n];
    for(int i=0;i<n;i++)
        count[(arr[i]/pos)%10]++;
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--)
        temp[--count[(arr[i]/pos)%10]]=arr[i];
    for(int i=0;i<n;i++)
        arr[i]=temp[i];
}

void radixSort(int arr[],int n)
{
    int max=maxArr(arr,n);
    for(int pos=1;max/pos;pos*=10)
        modifiedCountSort(arr,n,pos);
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
    radixSort(arr,n);
    cout<<"Array after sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
