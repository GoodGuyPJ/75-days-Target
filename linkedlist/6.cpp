#include<bits/stdc++.h>
using namespace std;
  class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
void insertAtTail(Node* &tail, int d){
  Node* temp = new Node(d);
  tail->next= temp;
  tail= temp;
}
 
 void printLL(Node* &head){
  if(head == NULL){
    cout<<"LL is empty"<<endl;
    return;
  }
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp =  temp->next;
  }
  cout<<endl;
}

int getlen(Node* &head){
    int len =0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp= temp->next;
    }
    return len;
}

 Node* MiddleLinkedlist(Node* &head){
    int len = getlen(head);
    int ans = len/2;
    Node* temp = head;
    int cnt =0;
    while(cnt< ans){
        temp= temp->next;
        cnt++;
    }
    return temp;
 }


//approch 2
 Node* approch2(Node* &head){
    Node* slow =head;
    Node* fast = head->next;
    while(fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast= fast->next;
        }
        slow= slow->next;
    }
    return slow;
 }

 


int main(){
    //find middle of linked list
    Node* node1= new Node(1);
    Node* head = node1;
    Node* tail= node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
  printLL(head);
    
    
    // Node* ans = MiddleLinkedlist(head);
    Node* ans = approch2(head);
    cout<<"middle element is "<<ans->data;
    
     


  return 0;
}