
#include <iostream>
using namespace std;

int n;
int *arr=new int[n];
void f(int x);

int main()
{
    cin>>n;
    f(0);
    delete []arr;
    return 0;
}
void f(int x)
{
    if(x==n)
    {
        for(int i=0;i<n;++i)
        {
            cout<<arr[i];
        }
        cout <<endl;
    }
    else
    {
        arr[x]=0;
        f(x+1);
        arr[x]=1;
        f(x+1);
    }
}
