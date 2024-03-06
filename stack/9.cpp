//next smaller Element
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.    
    vector<int> ans(n);
    for(int i=0; i<n; i++){
       ans[i]= -1;
       for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

//approch 2
stack using

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.    
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
   for(int i= n-1; i>=0; i--){
       int curr= arr[i];
       while(s.top()>=curr){
           s.pop();
       }
       ans[i]= s.top();
       s.push(curr);
   }
    return ans;
}
