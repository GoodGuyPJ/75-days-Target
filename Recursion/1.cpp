#include<bits/stdc++.h>
using namespace std;
 
 void f(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    f(i+1, arr, n);
 }
int main(){
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    f(0, arr, n);
        for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
 
  return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
 
//  void reverse1(int arr[], int l, int r){
//     if(l>=r)  return ;
//     swap(arr[l], arr[r]);
//     reverse(l+1, r-1);
     
//  }
 
// int main(){
    
//     int arr[]= {1, 2, 3, 4, 5};
//     int l =0, r= 5;
//     reverse1(arr,l, r);
//     for(int i=0; i<5; i++){
//         cout<<arr[i]<<" ";
//     }
 
//   return 0;
// }