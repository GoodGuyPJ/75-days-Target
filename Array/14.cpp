#include<bits/stdc++.h>
using namespace std;
/*
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes
Explanation:
a2[] is a subset of a1[]
*/ 
 
 bool checkset(int a1[], int a2[], int n1, int n2){
    sort(a1, a1+n1);
    sort(a2, a2+n2);
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            i++;
        }
        else if(a1[i]==a2[j]){
            i++; j++;
        }
        else if(a1[i]>a2[j]){
            return false;
        }
    }
    
        return true;
 
 }

int main(){
    int a1[] = {11, 7, 1, 13, 21, 3, 7, 3};
    int a2[] = {11, 3, 7, 1, 7};
    int n1= sizeof(a1)/sizeof(int);
    int n2= sizeof(a2)/sizeof(int);

    if (checkset(a1, a2, n1, n2) == true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
 
  return 0;
}