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



//merge 


Node* solve(Node* &first, Node* &second){
    if(first->next ==NULL) {
        first->next = second;
        return first;
    }
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2= second;
    Node* next2 = curr2->next;

    while(next1!=NULL && curr2!= NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2= curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
            if(next1==NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* mergeLL(Node* &first, Node* &second){
    if(first==NULL) return second;
    if(second==NULL) return first;
    if(first->data <= second->data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}


int main(){
    //single linkedlist
    Node* first= new Node(1);
    Node* second= new Node(0);
    
    Node* tail= first;
    Node* Head= second;
    
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 5);

    cout<<"ll 1"<<endl;
    printLL(first);
    cout<<"ll 2"<<endl;
    printLL(second);
    cout<<endl;

     mergeLL(first, second);
    printLL(first);

 
 
  return 0;
}