#include<iostream>
#include<string.h>
#define N 100005
using namespace std;
int nextj[N],resul;

string s,t;

void getnext()
{
    int tempk=0;
    for(int i=1; i < t.size(); i++)
    {
        while(tempk > 0 && t[i] != t[tempk])
            tempk=nextj[tempk - 1];
        if(t[i] == t[tempk]) tempk++;
        nextj[i]=tempk;
    }
}

int main()
{
    int T;
    cin>>T;
    for(int l=0;l<T;l++)
    {
        int len1,len2;
        cin>>len1>>len2;
        cin >> s >> t;
        memset(nextj, 0, sizeof(nextj));
        resul=0;
        getnext();
        int k=0;
        for(char i : s)
        {
            while(k>0 && t[k] != i)
                k=nextj[k - 1];
            if(t[k] == i) k++;
            if(k == t.size()) resul++;
        }
        cout << resul << endl;
    }

    return 0;
}