#include<iostream>
using namespace std;
typedef long long ll;

void swap(ll arr[],ll i,ll j)
{
    ll temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void sort(ll arr[],ll n)
{
    for(ll i=0;i<n-1;i++)
    {
        bool isSorted=true;
        for(ll j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr,j,j+1);
                if(isSorted)
                    isSorted=false;
            }
        }
        if(isSorted)
            break;
    }
}

void recursiveSort(ll arr[],ll n)
{
    if(n==1)
        return;
    bool isSorted=true;
    for(ll i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr,i,i+1);
            if(isSorted)
                isSorted=false;
        }
    }
    if(isSorted)
        return;
    recursiveSort(arr,n-1);
}

int main()
{
    ll n;
    cout<<"Enter size of array: ";
    cin>>n;
    ll arr[n];
    cout<<"Enter array elements: ";
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Before sorting array: ";
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    sort(arr,n);
    cout<<"After sorting array: ";
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
