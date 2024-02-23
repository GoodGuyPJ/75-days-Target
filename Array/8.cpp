#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n=11;
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} ;
    int mx= arr[0], step= arr[0] , jump= 1;
    if(arr[0]==0 && n>1){
        return -1;
    }
    if(n==1) return 0;

    for(int i=1; i<n; i++){
        if(i==n-1){
            cout<<jump;
             break;
        }
       
       if(step){
        mx = max(mx, arr[i]+i);
        step--;
       }

       if(step==0){
        if(i>=mx) return -1;
        jump++;
        step= mx-i;
       }

    }


 
  return 0;
}