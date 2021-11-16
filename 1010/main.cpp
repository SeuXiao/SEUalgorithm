#include <iostream>
using namespace std;

int main()
{
    int M,N,X;
    cin>>M;
    int *father=new int [M];
    bool *isFind= new bool [M];
    for(int i=0;i<M;i++)
    {
        cin>>N>>X;
        isFind[i]= false;
        int *arr=new int [N];
        for(int j=0;j<N;j++)
        {
            cin>>arr[j];
        }
        int mid, left = 0, right = N - 1;
        int temp;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if(X==arr[mid])
            {
                isFind[i]= true;
                father[i]=temp;
            }
            if (X < arr[mid])
            {
                temp=arr[mid];
                right = mid - 1;
            }
            else{
                temp=arr[mid];
                left=mid+1;
            }
        }
        if(!isFind[i]) father[i]=arr[mid];
    }
    for(int i=0;i<M;i++)
    {
        if(isFind[i]) cout<<"success, "<<"father is "<<father[i]<<endl;
        else cout<<"not found, "<<"father is "<<father[i]<<endl;
    }
}