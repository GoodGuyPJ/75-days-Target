/*
git remote add origin https://github.com/GoodGuyPJ/75-days-Target.git
git branch -M main
git push -u origin main

*/ 

#include<bits/stdc++.h>
using namespace std;
 
 vector<int> approach1(vector<int>& arr, int n, int target){
  map<int, int> mpp;
  for(int i=0; i<n ;i++){
    int a= arr[i];
    int more = target-a;
    if(mpp.find(more)!= mpp.end()){
      return {mpp[more], i};
    }
    mpp[a] = i;
  }
  return {-1, -1};
 }

int main(){
    vector<int> arr{2, 71 , 7, 15};
    int n = arr.size();
    int target = 9;
    vector<int> ans = approach1(arr, n, target);
    for(int i=0; i<ans.size(); i++){
      cout<<ans[i]<<" ";
    }
 
  return 0;
}