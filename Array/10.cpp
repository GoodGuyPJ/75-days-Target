#include<bits/stdc++.h>
using namespace std;
 
 void optimalsol(long long int arr1[], long long int arr2[], int n, int m){
      int left = n-1;
      int right = 0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left], arr2[right]);
            left--; right++;
        }
        else{
            break;
        }
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+n);
 }
 
int main(){
    int n=4, m=5; 
     
    long long int arr1[n];
    long long int arr2[m];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }
     optimalsol(arr1, arr2, n, m);
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0; i<m; i++){
        cout<<arr2[i]<<" ";
    }

 
  return 0;
}