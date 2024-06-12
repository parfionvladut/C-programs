#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}
// Merge sort
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}
void verify(int *B,int *D){
int l=0,a=0,f=0,n=3;
while(l<n & a<n && f==0){
     if(D[l]=B[a])
        f=1;
    else if(D[l]<B[a])
        l=l+1;
    else a=a+1;
}
if(f==1){
  cout<<"Solutie!\n";
}
}
// read input array and call mergesort
int main()
{
    int A[3]={1,3,2}, B[3]={9,5,4} , C[3]={20,6,10},D[30],i,m;
    merge_sort(A, 0, A[2]);
    merge_sort(B, 0, B[2]);
  for(i=0;i<3;i++){
    for(m=0;m<3;m++){
        D[i]=(A[i]+C[m])/2;

        cout<<D[i]<<" ";
    }
    verify(B,D);
  }

}
