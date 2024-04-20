//lower bound
// smaller index such that arr[ind] >= x
Approch 1
// lb= lower_bound(arr.begin(), arr.end(), x) - arr.begin(); -- get the index
#include<bits/stdc++.h>
using namespace std;
 approach 2
 int lowerbound(int arr[], int n, int x){
    int low = 0, high= n-1;
    int ans= n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>=x){
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
    int arr[]= {1, 2, 6, 6, 6, 6, 7};
    int n= sizeof(arr)/sizeof(int);
    int target;
    cin>>target;

    int lowerB= lowerbound(arr, n, target);
    cout<<lowerB;
  return 0;
}