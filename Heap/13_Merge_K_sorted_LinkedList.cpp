#include<bits/stdc++.h>

/*

class Node

{

public:

    int data;

    Node *next;

    Node()

    {

        this->data = 0;

        next = NULL;

    }

    Node(int data)

    {

        this->data = data; 

        this->next = NULL;

    }

    Node(int data, Node* next)

    {

        this->data = data;

        this->next = next;

    }

};

*/

class compare{

public:

    bool operator()(Node* a,Node* b){

        return a->data > b->data;

    }

};

 

Node *mergeKLists(vector<Node*> &listArray)

{

    priority_queue<Node*, vector<Node*>, compare > minHeap;

    int k = listArray.size();

 

    if(k == 0){

        return NULL;

    }

 

    //step1: push the heads of all lists into minHeap

    for(int i = 0; i < k; i++){

        if(listArray[i] != NULL){

            minHeap.push(listArray[i]);

        }

    }

 

    Node* head = NULL;

    Node* tail = NULL;

 

    while(!minHeap.empty()){

        Node* top = minHeap.top();

        minHeap.pop();

        

        // Add the next node from the popped list to minHeap

        if(top->next != NULL){

            minHeap.push(top->next);

        }

        

        // Update the head and tail pointers of the merged list

        if(head == NULL){

            head = top;

            tail = top;

        }

        else{

            tail->next = top;

            tail = top;

        }

    }

    return head;

}