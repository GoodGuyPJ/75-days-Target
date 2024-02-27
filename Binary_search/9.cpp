#include<bits/stdc++.h>
using namespace std;
 
 int miniEle(int arr[], int n){
    int l=0, h= n-1;
    while(l<=h){
        int mid= l+(h-l)/2;
        if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }
        else if(arr[mid]){

        }


    //left sorted
    if(arr[l]<= arr[mid]){

    }


    //right sorted




    }
 }

int main(){
    //minimum number in rotated sorted array
    int arr[]= {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr)/ sizeof(int);
    
    int mini= miniEle(arr, n); 
  return 0;
}