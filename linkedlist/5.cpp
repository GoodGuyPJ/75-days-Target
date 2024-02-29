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

 
 //approach 1
 Node* reverseLL1(Node* &head){
  if(head==NULL || head->next==NULL) return head;
  Node* prev = NULL;
  Node* curr = head;
  Node* forward = NULL;
  while(curr!=NULL){
    forward= curr->next;
    curr->next = prev;
    prev = curr;
    curr=forward;
  }
  return prev;
 }


//approach 2
Node* recursive_approach(Node* &head){
  if(head==NULL || head->next ==NULL) return head;
  Node* chotahead = recursive_approach(head->next);
    head->next->next= head;
    head->next = NULL;

    return chotahead;
}

int main(){
    //reverse a linked list code
    Node* node1= new Node(1);
    Node* head = node1;
    Node* tail= node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
  printLL(head);
    
    // reverseLL1(head);
    recursive_approach(head);
  printLL( tail);


  return 0;
}