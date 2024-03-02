#include<bits/stdc++.h>
using namespace std;
 
 class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        this->data= d;
        this->prev= NULL;
        this->next = NULL;
    }
    ~Node(){
       int val= this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }
 };

 void  insertAthead(Node* &head, Node* &tail, int d){
        if(head==NULL){
            Node* temp= new Node(d);
            head= temp;
            tail = temp;
        }
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

void  insertAttail(Node* &tail,  Node* &head, int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev= tail;
        tail= temp;
    }
 }

  void insertAtMiddle(Node* &head, Node* &tail, int position, int d){
  if(position == 1){
    insertAthead(head, tail, d);
    return;
  }
  Node* temp = head;
  int cnt=1;

  while(cnt<position-1){
    temp= temp->next;
    cnt++;
  }
   
  if(temp->next==NULL){
    insertAttail(tail, head, d);
    return;
  }

  Node* nodetoInsert= new Node(d);
  nodetoInsert->next = temp->next;
  temp->next->prev = nodetoInsert;
  temp->next = nodetoInsert;
  nodetoInsert->prev= temp;
}
 
 void deletionLL(Node* &head, Node* &tail, int position){
    if(position==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head= temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr= curr->next;
            cnt++;
        }
        curr->prev= NULL;
        prev ->next = curr->next;
        curr->next = NULL;
        delete curr;


    }
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
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAthead(head, tail, 1);
    
    // printLL(head);
    insertAttail(tail, head, 2);
    insertAttail(tail, head, 3);
    insertAttail(tail, head, 4);
    insertAttail(tail, head, 5);
    insertAttail(tail, head, 6);
    printLL(head);
    insertAtMiddle(head, tail, 4, 101);
    printLL(head);
    
    deletionLL(head, tail, 4);
    
    printLL(head);

    bool ans = iscircular(head);
    cout<<"is circular is or not "<<ans;


  return 0;
}