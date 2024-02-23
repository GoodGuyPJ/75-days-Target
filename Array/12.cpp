#include <bits/stdc++.h>
using namespace std;
//6 -2 -10 0 2 --> 
class Solution{
public: 
	long long maxProduct(vector<int> arr, int n) {
	    // code here
        long long p=1, s=1;
        long long res= INT_MIN;
        for(int i=0; i<n; i++){
            if(p==0) p=1;
            if(s==0) s= 1;

            p= p*arr[i];
            s= s*arr[n-1-i];
            res = max(res, max(p, s));
        }
	}
};

 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}