#include<bits/stdc++.h>
using namespace std;
 class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
 };
 
void insertatmiddle(Node* &tail, int element, int d){
    if(tail==NULL){
        Node* newNode= new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node* curr = tail;
        while(curr->data!= element){
            curr= curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteLL(Node* &tail, int val){
    if(tail== NULL){
        cout<<"circular LL empty";
        return;
    }
    

    else{
        Node* prev = tail;
        Node* curr= prev->next;
        while(curr->data != val){
            prev = curr;
            curr= curr->next;
        }
        if(curr==prev){
            tail=NULL;
        }
        else if(tail==curr){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

 void printLL(Node* &tail){
  if(tail == NULL){
    cout<<"LL is empty"<<endl;
    return;
  }
  Node* temp = tail;
  do
  {
    cout<<tail->data<<" ";
    tail= tail->next;
  } while (tail!= temp);
  
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

int count(Node* &head){
    int cnt   =1;
    Node* temp = head;
    while(temp!=head){
        cnt++;
        temp = temp ->next;

    }
    return cnt;
}

Node* splitLINkedlist(Node* &head, int count){
    
}




int main(){
    //break a LL in 2 parts
    Node* tail = NULL;
    insertatmiddle(tail, 1, 1);
    insertatmiddle(tail, 1, 2);
    insertatmiddle(tail, 2, 3);
    insertatmiddle(tail, 3, 4);
    insertatmiddle(tail, 4, 5);
    printLL(tail);

    

    bool ans = iscircular(tail);
    cout<<"is circular or not "<< ans<<endl;

    cout<<"breaking circular LL into 2 parts "<<endl;



  return 0;
}