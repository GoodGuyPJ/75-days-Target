#include<bits/stdc++.h>
using namespace std;
 
 class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data= data;
    this->next = NULL;
  }
 };
void insertAtHead(Node* &head, int d){
  Node* temp = new Node(d);
  temp->next= head;
  head= temp;
}

void insertAtTail(Node* &tail, int d){
  Node* temp = new Node(d);
  tail->next= temp;
  tail= temp;
}

void insertAtMiddle(Node* &head, Node* &tail, int position, int d){
  Node* temp = head;
  if(position == 1){
    insertAtHead(head, d);
  }
  if(temp->next==NULL){
    insertAtTail(tail, d);
  }
  int cnt=1;
  while(cnt<position-1){
    temp= temp->next;
    cnt++;
  } 
  
  Node* nodetoInsert= new Node(d);
  nodetoInsert->next = temp->next;
  temp->next = nodetoInsert;
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

int main(){
    //single linkedlist
    Node* node1= new Node(10);
    Node* head = node1;
    Node* tail= node1;
    // insertAtHead(head, 11);
    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    insertAtTail(tail, 15);
    insertAtMiddle(head, tail, 4, 0);
    printLL(head);
 
  return 0;
}