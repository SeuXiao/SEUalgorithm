#include <iostream>
using namespace std;

int Mergesort(int arr[], int brr[], int left,int right)
{
    if(left>=right) return 0;
    int mid=(left+right)/2;
    int count=Mergesort(arr,brr,left,mid)+Mergesort(arr,brr,mid+1,right);
    int i = left, j= mid + 1, k = left;
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            brr[k++]=arr[i++];
            count+=(j-(mid+1));
        } else{
            brr[k++]=arr[j++];
        }
    }
    while(i <= mid)
    {
        brr[k++] = arr[i++];
        count+=(j-(mid+1));
    }
    while(j <= right)
        brr[k++] = arr[j++];
    for(i=left; i <= right; i++)
        arr[i] = brr[i];
    return count;
}


int main()
{
    int m;
    cin>>m;
    int n;
    int result[m];
    for(int i=0;i<m;i++)
    {
        cin>>n;
        int arr[n];
        int brr[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            brr[j]=0;
        }
        result[i]=Mergesort(arr, brr, 0, n- 1);
    }
    for(int i=0;i<m;i++)
    {
        cout<<result[i]<<endl;
    }
}