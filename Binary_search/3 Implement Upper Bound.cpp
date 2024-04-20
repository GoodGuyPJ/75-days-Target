//Upper bound
smallest index such that arr[ind] > x
// lb= upper_bound(arr.begin(), arr.end(), x) - arr.begin(); -- get the index
#include<bits/stdc++.h>
using namespace std;
 
 int lowerbound(int arr[], int n, int x){
    int low = 0, high= n-1;
    int ans= n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>x){
            ans = mid;
            high= mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
 }
int main(){
    int arr[]= {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    int n= sizeof(arr)/sizeof(int);
    int target;
    cin>>target;

    int lowerB= lowerbound(arr, n, target);

    cout<<"array "<<arr[lowerB]<<endl;
    cout<<"index "<<lowerB;
  return 0;
}