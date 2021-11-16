#include <iostream>
#include "string.h"
using namespace std;

int main()
{
    int M;
    cin>>M;
    int minsize[M];
    int index[M];
    for(int i=0;i<M;i++)
    {
        minsize[i]=1;
        index[i]=1;
    }
    for(int j=0;j<M;j++)
    {
        int N;
        cin >> N;
        int *arr = new int[N];
        int *brr=new int [N];
        for(int i=0;i<N;i++)
        {
            brr[i]=1;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int result = 0;
        for (int i = 1; i < N; i++)
        {
            for (int k = 0; k < i; k++)
            {
                if (arr[i] < arr[k])
                    brr[i] = brr[i]>(brr[k] + 1)?brr[i]:(brr[k] + 1);
            }
            if (brr[i] > result) result = brr[i];
        }
        index[j]=result;
        int results = 0;
        for(int i=0;i<N;i++)
        {
            brr[i]=1;
        }
        for (int i = 1; i < N; i++)
        {
            for (int k = 0; k < i; k++)
            {
                if (arr[i] > arr[k])
                    brr[i] = brr[i]>(brr[k] + 1)?brr[i]:(brr[k] + 1);
            }
            if (brr[i] > results) results = brr[i];
        }
        minsize[j]=results;
    }
    for(int k=0;k<M;k++)
    {
        cout<<index[k]<<" "<<minsize[k]<<endl;
    }
}
