#include <iostream>
using namespace std;

int arr[1000];
int brr[1000];
int temp=0;
int quicksort(int left, int right, int depth)
{
    if(left >= right)
    {
        return 0;
    }
    int pivotpos = left;
    for(int i=left; i <= right; i++) {
        if(arr[i]<arr[left])
        {
            pivotpos++;
            temp = arr[pivotpos];
            arr[pivotpos] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[left];
    arr[left] = arr[pivotpos];
    arr[pivotpos] = temp;

    if(depth==1)
    {
        brr[pivotpos] = arr[pivotpos];
    }
    if(depth==2)
    {
        for(int i=left; i <= right; i++)
        {
            brr[i] = arr[i];
        }
    }

    quicksort(left, pivotpos - 1, depth + 1);
    quicksort(pivotpos + 1, right, depth + 1);

    return 0;
}

int main() {
    int m,n;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>n;
        for(int j=0; j<n; j++) {
            cin>>arr[j];
        }
        quicksort(0, n-1, 1);
        for(int j=0; j<n; j++) {
            cout<<brr[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
