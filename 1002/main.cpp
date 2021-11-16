#include <iostream>
using namespace std;

int main()
{
    int m;
    cin>>m;
    for(int n=0;n<m;n++)
    {
        int arr[1000];
        cin>>arr[0];
        for(int k=1;k<=arr[0];k++)
        {
            cin>>arr[k];
        }
        int MIN = arr[1]<arr[2]?arr[1]:arr[2];
        int secmin = arr[1]<arr[2]?arr[2]:arr[1];
        for (int i = 2; i <= arr[0]; i++ )
        {
            if (arr[i]<MIN)
            {
                    secmin=MIN;
                    MIN=arr[i];
            }
            else {
                if (arr[i] < secmin)
                    secmin = arr[i];
            }
        }
        cout<<secmin<<endl;
    }
    return 0;
}

