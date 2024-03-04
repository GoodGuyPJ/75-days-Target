//insert an element at bottom of a given stack
#include<bits/stdc++.h>
using namespace std;
 
void insertATBottom(stack<int> & s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    insertATBottom(s, x);
    s.push(num);
}


//reverse stack using recursion

void reverseStack(stack<int> & s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    reverseStack(s);
    insertATBottom(s, num); 
}

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
 
int main(){
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(9);

    insertATBottom(s, 10);
    printStack(s);
    cout<<endl;
    cout<<"reverse stack is: ";
    reverseStack(s);
    printStack(s);

 
  return 0;
}