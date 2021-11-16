#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int M;
    cin>>M;
    bool result[M];
    for(int i=0;i<M;i++) {
        int N,X;
        cin>>N>>X;
        result[i]= false;
        int arr[N];
        for(int j=0;j<N;j++)
        {
            cin >> arr[j];
        }
        sort(arr,arr+N);
        int left=0,right=N-1;
        while(left<right)
        {
            if((arr[left] + arr[right]) > X) right--;
            else if((arr[left] + arr[right]) < X) left++;
            else {
                result[i]= true;
                break;
            }
        }

    }
    for(int i=0;i<M;i++)
    {
        if(result[i]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}