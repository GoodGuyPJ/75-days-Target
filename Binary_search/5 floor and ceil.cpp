// floor and ceil in sorted array
//floor- largest no in array <= x
//ceil - smallest no in array >= x

#include<bits/stdc++.h>
using namespace std;
 
 int floorfunc(vector<int>& arr, int x){
    int ans = -1;
    int low = 0, high= arr.size()-1;
    while(low<= high){
        int mid = (low+high)/2;
        if(arr[mid]<= x){
            ans= arr[mid];
            low= mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
 }
int main(){
    int n;cin>>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int val;
    cin>>val;

    int floorofthearray = floorfunc(arr, val);
    int ceil1 = lower_bound(arr.begin(), arr.end(), val)- arr.begin();

    cout<<"floor is "<<floorofthearray<<" ceil of array "<<arr[ceil1];

 
  return 0;
}
