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

Node* sortList(Node* &head){
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        if(temp->data==0) zerocount++;
       else if(temp->data==1) onecount++;
       else if(temp->data==2) twocount++;
       temp = temp->next;
    }
     temp = head;
     while(temp!=NULL){
        if(zerocount!=0){
            temp->data = 0;
            zerocount--;
        }
        else if(onecount!=0){
            temp->data = 1;
            onecount--;
        }
        else if(twocount!=0){
            temp ->data = 2;
            twocount--;
        }
        temp= temp ->next;
     }

    return head;
}

void tailInsert(Node* &tail, Node* &curr){
    tail ->next = curr;
    tail = curr;
}

Node* sortLL2(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* zerotail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* onetail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twotail =twoHead;
    Node* temp = head;
    while(temp!=NULL){
        int val = temp->data;
        if(val == 0){
            tailInsert(zerotail, temp);
        }
        else if(val == 1){
            tailInsert(oneHead, temp);
        }
        else if(val == 2){
            tailInsert(twotail, temp);
        }
        temp = temp->next;
    }


    //merge the lists
    if(oneHead->next!=NULL){
        zerotail->next = oneHead->next;
    }
    else{
        zerotail->next = twotail->next;
    }
    onetail->next = twotail->next;

    twotail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}



int main(){
    //single linkedlist
    Node* node1= new Node(0);
    Node* head = node1;
    Node* tail= node1;
    insertAtHead(head, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtMiddle(head, tail, 4, 2);
    printLL(head);
    cout<<"aPProach 1 usint cout storing "<<endl;
    // sortList(head);

    Node * ans = sortLL2(head);
    cout<<"aPProach 2 usint cout storing "<<endl;
    printLL(ans);
 
 
  return 0;
}