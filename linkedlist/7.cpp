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

Node* reverseInKgroups(Node* &head, int k){
    Node* next1= NULL;
    Node* curr= head;
    Node* prev = NULL;
    int cnt = 0;
    while(curr!=NULL && cnt<k){
        next1 = curr->next;
        curr->next = prev;
        prev= curr;
        curr= next1;
        cnt++;
    }
    if(next1!=NULL){
        head->next= reverseInKgroups(next1, k);
    }
    return prev;
}



int main(){
    //find reverse ll in K- Groups
    Node* node1= new Node(1);
    Node* head = node1;
    Node* tail= node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
  printLL(head);
    
    int k= 2;
    Node* ans= reverseInKgroups(head, k);
     cout<<"reverse LL in k-groups "<<endl;
     
     printLL(ans);


  return 0;
}