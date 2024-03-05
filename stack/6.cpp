#include<bits/stdc++.h> 
using namespace std;
 void printStack(stack<int> s){
    if(s.empty()){
        return;
    }
    int x =s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);
}

void insertSorted(stack<int> &s, int n){
    if(s.empty() || !s.empty() && s.top()<n){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    insertSorted(s, n);
    s.push(num);
}

void sortStack(stack<int> &stack){
    if(stack.empty()){
        return ;
    }
    int n= stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack, n);
}
 
int main(){
 
  stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);  
    s.push(3);

    cout<<"stack before sorting "<<endl;
    printStack(s);
    
    cout<<"stack after sorting "<<endl;
    sortStack(s);

    printStack(s);


    
      
     

     

  
 


  return 0;
}