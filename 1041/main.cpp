#include <iostream>
#include<algorithm>
using namespace std;

double findtheK(int *nums1, int n, int *nums2, int m, int k)
{
    if (n > m)
        return findtheK(nums2, m, nums1, n, k);
    if (n == 0)
        return nums2[k - 1];
    if (k == 1)
        return min(nums1[0], nums2[0]);
    int temp1 = min(k / 2, n), temp2 = k - temp1;
    if (nums1[temp1 - 1] < nums2[temp2 - 1])
        return findtheK(nums1 + temp1, n - temp1, nums2, m, k - temp1);
    else if (nums1[temp1 - 1] > nums2[temp2 - 1])
        return findtheK(nums1, n, nums2 + temp2, m - temp2, k - temp2);
    else
        return nums1[temp1 - 1];
}

double findres(int *nums1, int n, int *nums2, int m)
{
    int Len = n + m;
    if (Len %2==1)
        return findtheK(nums1, n, nums2, m, Len / 2 + 1) / 1.0;
    else
        return (findtheK(nums1, n, nums2, m, Len / 2) + findtheK(nums1, n, nums2, m, Len / 2 + 1)) / 2.0;
}

int main()
{
    int nums;
    cin >> nums;
    double res[nums];
    for(int i=0; i < nums; i++)
    {
        int m,n;
        cin>>n;
        cin>>m;
        int nums1[n];
        int nums2[m];
        for(int j=0;j<n;j++)
        {
            cin>>nums1[j];
        }
        for(int j=0;j<m;j++)
        {
            cin>>nums2[j];
        }
        res[i]= findres(nums1, n, nums2, m);
    }
    for(int j=0; j < nums; j++)
    {
        cout<<res[j]<<endl;
    }
    return 0;
}
