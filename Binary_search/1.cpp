#include<bits/stdc++.h>
using namespace std;
 
 int binarysearch(int arr[], int n, int l, int h, int target){
    if(l>=h) return -1;
    while(l<=h ){
        int mid = l+(h-l)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            l= mid+1;
        }
        else{
            h= mid-1;
        }
    }
    return -1;

 }
 
int main(){
    int arr[] = { 3, 4, 6, 7, 9, 12, 16, 17};
    int n= sizeof(arr)/sizeof(int);
    int low =0, target = 17; 
    int high= n-1;
    cout<<binarysearch(arr, n, low, high, target);
 
  return 0;
}