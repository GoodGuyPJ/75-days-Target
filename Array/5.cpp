#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n =5;
    int a[5] = {-1, 2, -3, 0, 1};
    int j=0;
    for(int i=0; i<n; i++){
        if(a[i]<0){
            swap(a[i], a[j]);
            j++;
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

 
  return 0;
}