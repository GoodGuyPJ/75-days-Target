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
    
    

  return 0;
}