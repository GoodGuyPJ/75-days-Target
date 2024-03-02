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

bool detectcycle(Node* &head){
    if(head==NULL) return false;
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp!=NULL){
        if(visited[temp]== true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

bool floyedcycle(Node* &head){
    if(head==NULL) return false;
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL){
        fast= fast->next;
        if(fast!= NULL){
            fast = fast->next;
        }
        slow= slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    //Detect cycle in Linked list
    Node* node1= new Node(1);
    Node* head = node1;
    Node* tail= node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    printLL(head);
    
    bool ans1 = detectcycle(head);
    cout<<"detect cycle using approch 1 "<< ans1<<endl;
    bool ans2 = floyedcycle(head);
    cout<<"detect cycle using approch 2 (floyed cycle) "<< ans2<<endl;
    

  return 0;
}