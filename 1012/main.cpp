#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct position{
    double x,y;
    position friend operator -(position a, position b)
    {
        return {a.x-b.x,a.y-b.y};
    }
}points[2001],resstack[2001];

int N;

double distance(position a, position b)
{
    position c= a - b;
    return sqrt(c.x*c.x+c.y*c.y);
}

double chacheng(position a, position b)
{
    return a.x*b.y-a.y*b.x;
}

double funcationX(position p1, position p2, position p3)
{
    return chacheng(p2 - p1, p3 - p1);
}

int comparewithangle(position a, position b)
{
    double temp= chacheng(a - points[1], b - points[1]);

    if(temp > 0) return 1;

    if(temp == 0 && distance(a, points[1]) < distance(b, points[1])) return 1;

    return 0;
}

int solution()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> points[i].x >> points[i].y;

    int k = 1;

    for (int i = 2; i <= N; i++)
        if (points[i].y < points[k].y || (points[i].y == points[k].y && points[i].x < points[k].x))
            k = i;

    swap(points[1], points[k]);

    sort(points + 2, points + 1 + N, comparewithangle);

    resstack[1] = points[1];
    resstack[2] = points[2];

    int counts = 2;

    for (int i = 3; i <= N; i++)
    {
        while (counts >= 2 && funcationX(resstack[counts - 1], resstack[counts], points[i]) <= 0) counts--;
        resstack[++counts] = points[i];
    }
    for (int i = 1; i <= counts; i++)
    {
        cout << resstack[i].x << " " << resstack[i].y <<endl;
    }
}

int main()
{
    int M;
    cin>>M;
    for(int l=0;l<M;l++) {
        cout<<"case "<<l+1<<":"<<endl;
        solution();
    }
    return 0;
}