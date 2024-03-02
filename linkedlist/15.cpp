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


bool checkpal(vector<int> arr){
    int n = arr.size();
    int s = 0, e = n-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++, e--;
    }
    return true;
}

bool ispalindrome(Node* head){
    vector<int> ans;
    Node* temp = head;
    while(temp!=NULL){
        ans.push_back(temp->data);
        temp= temp->next;
    }
    return checkpal(ans);
}


Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!= NULL && fast->next!=NULL){
        fast  = fast->next->next;
        slow = slow->next;

    }
    return slow;
}


Node* reverse(Node* head){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    while(curr!= NULL){
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
    }
    return prev;
}

bool approch2(Node* &head){
    if(head->next == NULL) return true;
    Node* middle= getMid(head);
    Node* temp = middle->next;
    middle->next = reverse(temp);
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2!=NULL){
        if(head1->data!= head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp  = middle->next;
    middle->next = reverse(temp);

    return true;

}


int main(){
    //single linkedlist
    Node* node1= new Node(10);
    Node* head = node1;
    Node* tail= node1;
    // insertAtHead(head, 11);
    insertAtTail(tail, 11);
    insertAtTail(tail, 10);
     
    printLL(head);

    cout<<ispalindrome(head)<<endl;


    cout<<approch2(head)<<endl;
 
 
  return 0;
}