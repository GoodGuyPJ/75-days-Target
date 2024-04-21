#include<bits/stdc++.h>
using namespace std;
 
 int miniEle(int arr[], int n){
    int l=0, h= n-1;
    int ans = INT_MAX;
    while(l<=h){
        int mid= l+(h-l)/2;
        if(arr[l] <= arr[h]){
            ans = min(ans, arr[l]);
            break;
        }
        if(arr[l] <= arr[mid]){
            ans = min(ans, arr[l]);
            l = mid+1;
        }
        else{
            h= mid-1;
            ans = min(ans, arr[mid]);
        }
        return ans;
    }
 }

int main(){
    //minimum number in rotated sorted array
    int arr[]= {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr)/ sizeof(int);
    
    int mini= miniEle(arr, n); 
  return 0;
}