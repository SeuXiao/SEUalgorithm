#include<iostream>

using namespace std;

int arr[1001],brr[1001];
void mergesort(int left, int right, int depth)
{
    if(left<right)
    {
        int mid = (left + right) / 2;
        mergesort(left, mid, depth + 1);
        mergesort(mid + 1, right, depth + 1);
        int l = left, mi = mid + 1, k = left;
        while (l <= mid || mi <= right)
        {
            if (l <= mid && arr[l] < arr[mi] || mi > right)
                brr[k++] = arr[l++];
            else brr[k++] = arr[mi++];
        }
        for (k = left; k <= right; k++)arr[k] = brr[k];
        if (depth == 3)
            for (int i = left; i <= right; i++)
                cout << arr[i] << " ";
    }
}

int main()
{
    int m,n;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin >> arr[i];
        }
        mergesort(0, n - 1, 1);
        cout<<endl;
    }
}