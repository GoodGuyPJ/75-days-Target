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
Node* merge(Node* left, Node* right){
    if(left==NULL) return right;
    if(right==NULL) return left;
    Node* ans = new Node(-1);
    Node* temp  = ans;

    while(left!=nullptr && right!= NULL){
        if(left->data<right->data){
            temp ->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp ->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left!=NULL)
    {
        temp ->next = left;
            temp = left;
            left = left->next;
    }
    while(right!=NULL){
          temp ->next = right;
            temp = right;
            right = right->next;
    }

    ans  = ans->next;
    return ans;
    
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast= fast->next->next;
        slow =slow->next;
    }
    return slow;
}

//mergesort
Node* mergesort(Node* &head){
    if(head ==NULL){
        return head;
    }
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergesort(left);
    right = mergesort(right);

    Node* result = merge(left, right);
    return result;
}


int main(){
    //single linkedlist
    Node* node1= new Node(1);
    Node* head = node1;
    Node* tail= node1;
    // insertAtHead(head, 11);
    insertAtTail(tail, 5);
    insertAtTail(tail, 2);
    insertAtTail(tail, 6);
    insertAtTail(tail, 3);
    insertAtTail(tail, 0);
    insertAtTail(tail, 4);
    printLL(head);

    Node* ans = mergesort(head);

    cout<<"merge sorted LL is "<<endl;
    printLL(ans);
 
 
  return 0;
}