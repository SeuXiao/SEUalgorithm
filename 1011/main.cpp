#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

struct position{
    int x;
    int y;
} points[100001], tpos[100001];
int n;

double getdistance(int i, int j)
{
    return 1.0 * (points[i].x - points[j].x) * (points[i].x - points[j].x) + 1.0 * (points[i].y - points[j].y) * (points[i].y - points[j].y);
}

int comparewithXY (const void * a, const void * b)
{
    position *temp1 = (position *)a;
    position *temp2 = (position *)b;
    if(temp1->x != temp2->x)
    {
        return temp1->x - temp2->x;
    }
    else {
        return temp1->y - temp2->y;
    }
}

int comparewithY (const void * a, const void * b)
{
    position *temp1 = (position *)a;
    position *temp2 = (position *)b;
    return temp1->y - temp2->y;
}

double divide(int left, int right)
{
    if(left >= right) {
        return ((long long int)2)<<60;
    }
    if(left + 1 == right) {
        return getdistance(left, right);
    }

    int mid = (left + right) / 2;
    int midx = points[mid].x;

    double d1 = divide(left, mid);
    double d2 = divide(mid+1, right);

    double nowmin = d1 > d2 ? d2 : d1;

    int k = 0;
    for(int i=left; i <= right; i++)
    {
        if(abs(midx - points[i].x) < nowmin)
        {
            tpos[k].x = points[i].x;
            tpos[k].y = points[i].y;
            k++;
        }
    }
    qsort(tpos, k, sizeof(position), comparewithY);

    for(int i=0; i<k-6; i++) {
        for(int j=1; j<=6; j++)
        {
            double tempdistance = 1.0 * (tpos[i].x - tpos[i + j].x) * (tpos[i].x - tpos[i + j].x) + 1.0 * (tpos[i].y - tpos[i + j].y) * (tpos[i].y - tpos[i + j].y);
            if(tempdistance < nowmin)
            {
                nowmin = tempdistance;
            }
        }
    }

    return nowmin;
}

double getmin(int i,int j)
{
    return sqrt(divide(i, j));
}
int main()
{
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>n;
        for(int j=0; j<n; j++)
        {
            cin>>points[j].x>>points[j].y;
        }

        qsort(points, n, sizeof(position), comparewithXY);

        cout<<fixed<<setprecision(2)<<getmin(0,n-1)<<endl;
    }
}

