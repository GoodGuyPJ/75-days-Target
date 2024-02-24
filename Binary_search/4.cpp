// search insert postion-- use LOWER BOUND 
#include<bits/stdc++.h>
using namespace std;
 
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
    int n;cin>>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int serachINsert_Position = lower_bound(arr.begin(), arr.end(), 4)- arr.begin();
    cout<<"serach insert positoin "<<serachINsert_Position<<endl;
 
  return 0;
}