#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
     int nums;
     cin>>nums;
     int m;
     int days[366]={0};
     int costs[3];
     int data[]={1,7,30};
     int prize[366]={0};
     int result[nums];
     for(int i=0;i<nums;i++)
    {
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>days[j];
        }

        for(int j=0;j<3;j++)
        {
            cin>>costs[j];
        }

        int temp=1;
        int temp1;

        for(int j=0;j<m;j++)
        {
            while(temp<days[j])
            {
                prize[temp]=prize[temp-1];
                temp++;
            }

            prize[temp]=100000;

            for(int k=0;k<3;k++)
            {
                temp1=temp-data[k];
                if(temp1<0)  temp1=0;
                prize[temp]=min(prize[temp],prize[temp1]+costs[k]);
            }

            temp++;
        }

        result[i]=prize[days[m-1]];
    }
     for(int i=0;i<nums;i++)
     {
         cout<<result[i]<<endl;
     }
}