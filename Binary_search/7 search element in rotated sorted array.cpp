#include<bits/stdc++.h>
using namespace std;
 
 int elementSearch(int arr[], int n , int val){
    int low = 0, high = n-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(arr[mid]== val) return mid;
        //left sorted
        if(arr[low]<= arr[mid]){
            if(arr[low]<=val && val <= arr[mid]){
                high = mid-1;
            }
            else{ low = mid+1; }
        }
        //right sorted
        else{
            if(arr[mid]<=val && val<= arr[high]){
                low = mid+1;
            }
            else{ high = mid-1; }
        }
    }
    return -1;
 }

int main(){
    //search element in rotated sorted array
    int arr[]= {7,8, 9, 1,2,3,4,5,6};
    int n = sizeof(arr)/ sizeof(int);
    int element = 1;
    int ele = elementSearch(arr, n, element);
    cout<<"search element in rotated sorted array "<<ele;
    cout<<endl;
  return 0;
}