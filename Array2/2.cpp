#include<bits/stdc++.h>
using namespace std;
 //2 sum but array is sorted

 vector<int> approach2(vector<int>& arr, int n, int target){
   int i=0, j = n-1;
   while(i<j){
    int sum = arr[i]+arr[j];
    if(sum>target) j--;
    else if(sum<target) i++;
    else{
        return {i+1, j+1};
    }
   }
   return {};
 }

int main(){
    vector<int> arr{1, 2, 4, 6, 8, 9};
    int n = arr.size();
    int target = 6;
    vector<int> ans = approach2(arr, n, target);
    for(int i=0; i<ans.size(); i++){
      cout<<ans[i]<<" ";
    }
 
  return 0;
}