//queue

#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    queue<int> q;
    q.push(11);
    cout<<"ront of queue : "<<q.front()<<endl;
    q.push(12);
    cout<<"ront of queue : "<<q.front()<<endl;
    q.push(13);
    cout<<"ront of queue : "<<q.front()<<endl;
    cout<<"size of queue "<<q.size()<<endl;
    q.pop();
    
    cout<<"size of queue is "<<q.size()<<endl;
 


 
  return 0;
}