#include <iostream>
#include<stack>
using namespace std;

struct points{
    int color;
    int location;
};
int main()
{
    int m;
    cin>>m;
    int res[m];
    int n;
    for(int i=0;i<m;i++)
    {
        cin>>n;
        int minlen=0;
        stack<points> s1;
        int temp;
        int len=0;
        int counts=1;
        for(int j=1;j<=2*n;j++)
        {
            cin>>temp;
            points temp1;
            temp1.color=temp;
            temp1.location=j;
            if(s1.empty()||s1.top().color+temp1.color!=1) {
                s1.push(temp1);
                len++;
            }
            if(s1.top().color+temp1.color==1)
            {
                minlen=minlen+j-s1.top().location;
                s1.pop();

            }
        }
        res[i]=minlen;
    }
    for(int i=0;i<m;i++)
    {
        cout<<res[i]<<endl;
    }
}