#include<iostream>
#define num 110
using namespace std;

int main()
{
    int n;
    char arr[num];
    cin>>n;
    cin.getline(arr,num);
    for(int i=0; i<n; i++)
    {
        int count = 0;
        cin.getline(arr,num);
        for(int j=0; arr[j]!='\0'; j++)
        {
            if(arr[j]>='0' && arr[j]<='9')
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}