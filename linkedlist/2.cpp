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
  ~Node(){
    int val = this->data;
    if(this->next!=NULL){
      delete next;
      next =NULL;
    }
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

void deletionNode(int position, Node* &head){
  if(position==1){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete(temp);
  }
  else{
    Node* curr= head;
    Node* prev= NULL;
    int cnt =1;
    while(cnt<position){
      prev = curr;
      curr= curr->next;
      cnt++;
    }
    prev->next= curr->next;
    curr->next = NULL;
    delete(curr);
  }
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

bool iscircular(Node* &head){
  if(head==NULL) return true;

  Node* temp = head->next;
  while(temp!=NULL && temp!=head){
    temp= temp->next;
  }
  if(temp== head) return true;

  return false;
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

    deletionNode(4, head);
    printLL(head);

    bool ans = iscircular(head);
    cout<<"is circular or not "<<ans<<endl;
 
  return 0;
}