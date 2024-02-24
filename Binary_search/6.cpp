#include<bits/stdc++.h>
using namespace std;
 
 int firstOccurrence(vector<int>& arr, int n, int k){
    int l=0, h= n-1;
    int first = -1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]== k){
            first= mid;
            h = mid-1;
        }
        else if(arr[mid]< k) l= mid+1;
        else h = mid-1;
    }
    return first;
 }
 
 int lastOccurrence(vector<int>& arr, int n, int k){
    int l=0, h= n-1;
    int last = -1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]== k){
            last= mid;
            l = mid+1;
        }
        else if(arr[mid]< k) l= mid+1;
        else h = mid-1;
    }
    return last;
 }

int main(){
    int n =10;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int val=6;
    int firstele = firstOccurrence(arr, n, val);
    int lastele = lastOccurrence(arr, n, val);

    cout<<"first occurence of element: "<<firstele<<endl;
    cout<<"last occurence of element: "<<lastele<<endl;

 
  return 0;
}