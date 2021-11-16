#include <iostream>
using namespace std;

int main()
{
    int nums;
    cin >> nums;
    bool res[nums];
    for(int i=0; i < nums; i++)
    {
        res[i]= false;
    }
    for(int i=0; i < nums; i++)
    {
        int m,n,target;
        cin>>m>>n>>target;
        int arr[m][n];
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                cin>>arr[j][k];
            }
        }
        int s = 0, t = n - 1;
        while (s < m && t >= 0) {
            if (arr[s][t] == target)
            {
                res[i]= true;
                break;
            }
            else if (arr[s][t] > target)
            {
                t--;
            }
            else
            {
                s++;
            }
        }
    }
    for(int j=0; j < nums; j++)
    {
        if(res[j]) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}
