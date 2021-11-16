#include <iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m;
    int temp;
    int **arr=new int*[m];
    for(int i=0;i<m;i++)
    {
        arr[i]=new int[1050];
    }
    for(int i=0;i<m;i++)
    {
        cin >> n;
        arr[i][0]=n;
        for (int k = 1; k <= n; k++)
        {
            cin >> arr[i][k];
        }
        for(int j=1;j<n;j++)
        {
            if(arr[i][j]>arr[i][j+1])
            {
                temp=arr[i][j+1];
                arr[i][j+1]=arr[i][j];
                arr[i][j]=temp;
            }
        }

    }
    for(int i=0;i<m;i++)
    {
        for (int l = 1; l <= arr[i][0]; l++)
        {
            cout<<arr[i][l]<<" ";
        }
        cout<<endl;
    }
    delete []arr;
    return 0;
}