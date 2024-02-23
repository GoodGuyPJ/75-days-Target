#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[n], i;
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int small = a[0]+k;
    int big = a[n-1]-k;
    for(i =0; i<n-1; i++){
        int sub = a[i]-k;
        int ad= a[i]+k;

        if(sub>=small || ad<=big){
            continue;
        }
        else if(big-sub <= ad-small){
            small = sub;
        }
        else {
            big = ad;
        }
    }
    cout<<min(big-small, a[n-1]-a[0]);
 
  return 0;
}