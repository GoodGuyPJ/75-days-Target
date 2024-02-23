#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
int    N = 4;
int    Arr[] = {-1,-2,-3,-4};
 
long long int cs=Arr[0], ms= Arr[0];
for(int i=1; i<N; i++){
     cs= max(Arr[i] ,cs+ Arr[i]);
     ms = max(ms, cs);
}
cout<<ms<<endl;

 
  return 0;
}

/*
long long int maxnum = INT_MIN, cursum = 0;
 
    for (int i = 0; i < n; i++) {
        cursum = cursum + arr[i];
        if (maxnum < cursum)
            maxnum = cursum;
 
        if (cursum < 0)
            cursum = 0;
    }
    return maxnum; 
*/