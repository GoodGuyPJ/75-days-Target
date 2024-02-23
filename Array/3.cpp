#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int k = 3;
    int arr[]= {7, 10, 4 ,3 ,20, 15};
    int n = sizeof(arr)/ sizeof(int);
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    cout<<arr[k-1]<<" "<<arr[n-k];

  return 0;
}