#include<bits/stdc++.h>
using namespace std;
 
 class Solution{
    public:
    void multiply(int n, vector<int>& num){
        int carry=0;
        for(int i=0; i<num.size(); i++){
            int number= n*num[i];
            num[i] = (char)((number+carry)% 10);
            carry = (number+carry)/10;
        }
        while(carry){
            num.push_back(carry%10);
            carry/=10;
        }
    }
    vector<int> factorial(int n){
        vector<int> num;
        num.push_back(1);
        for(int i=2; i<=n; i++){
            multiply(i, num);
        }
        reverse(num.begin(), num.end());
        return num;
    }
 };
 
int main(){
    int n;
    cin>>n; 

    Solution largefactorial;

    vector<int> res = largefactorial.factorial(n);
    for(int i=0; i<res.size(); i++){
        cout<<res[i];
    }
    cout<<endl;
  return 0;
}