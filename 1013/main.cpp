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
    int M,N;
    cin>>M;
    int counts[M];
    for(int i=0;i<M;i++)
    {
        cin>>N;
        int arr[N];
        int brr[N];
        for(int j=0;j<N;j++)
        {
            cin>>arr[j];
            brr[i]=0;
        }
        counts[i]=Mergesort(arr,brr,0,N-1);
    }
    for(int k=0;k<M;k++)
    {
        cout<<counts[k]<<endl;
    }

}