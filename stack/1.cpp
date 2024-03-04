#include<bits/stdc++.h> 
using namespace std;
 
 /*class Stack{
    public:
    int top;
    int *arr;
    int size;

    Stack(int size){
        this->size = size;
        arr = new  int[size];
        top = -1;
    }
     void push(int element){
        if(size-top>1){
            top++;
            arr[top]= element;
        } else{
            cout<<"stack overflw"<<endl;
        }
     }
     void pop(){
        if(top>=0){
            top--;
        } else{
            cout<<"stack UnderFlow"<<endl;
        }
     }

     int peek(){
        if(top>=0){
            return arr[top];
        }else {
            cout<<"stack empty"<<endl; 
            return -1;
        }
     }

     bool isempty(){
        if(top==-1){
            cout<< "stack is empty"<<endl;
            return -1;
        } else{
            cout<<"stack have some elements"<<endl;
        }
     }


 };
 

 */
//stack implementation using linked list
class StackNode{
    public:
    int data;
    StackNode* next;
    int size;

    StackNode(int d){
        data= d;
        next = NULL;
    }
};

class MYstack {
    StackNode* top;
    int size;
    public:
    MYstack(){
        top= NULL;
        size=0;
    }

    void stackPush(int x){
        StackNode* element = new StackNode(x);
        element->next = top;
        top = element;
        size++;
        // cout<<"element Pushed"<<endl;
    }

    int pop(){
        if(top==NULL){
            return -1;
        }
        int topDAta= top->data;
        StackNode* temp = top;
        top= top->next;
        delete temp;
        return topDAta;
    }

    int stackSize(){
        return size;
    }

    bool stackisEmpty(){
        return top == NULL;
    }

    int stackPeek(){
        if(top==NULL) return -1;
        return top->data;
    }

    void printStack() {
        StackNode* current = top;
        while(current!=NULL){
            cout<<current->data<<" ";
            current= current->next;
        }
    }
};

int main(){
 /* 
  stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.top()<<endl;
    if(s.empty()){
        cout<<"stack empty"<<endl;
    }
    else{
        cout<<"not empty "<<endl;
    }

 
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    st.isempty();
*/
/***************/
// stack implemention using Linked list
 MYstack s;
 s.stackPush(1);
 s.stackPush(2);
 s.stackPush(3);
 s.stackPush(4);
 s.stackPush(5);

//  s.printStack();
 
 cout<<s.pop()<<endl;
 cout<<s.stackSize()<<endl;
 cout<<s.stackPeek()<<endl;

 s.printStack();





  return 0;
}