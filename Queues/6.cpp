// C++ program for the above approach
//singly queue linked list
/*
#include <bits/stdc++.h>
using namespace std;

class QNode {
    public:
	int data;
	QNode* next;
	QNode(int d)
	{
		data = d;
		next = NULL;
	}
};

class Queue {
    public:
	QNode *front, *rear;

	Queue() { front = rear = NULL; }

	void enQueue(int x)
	{

		// Create a new LL node
		QNode* temp = new QNode(x);

		// If queue is empty, then
		// new node is front and rear both
		if (rear == NULL) {
			front = rear = temp;
			return;
		}

		// Add the new node at
		// the end of queue and change rear
		rear->next = temp;
		rear = temp;
	}

	// Function to remove
	// a key from given queue q
	void deQueue()
	{
		// If queue is empty, return NULL.
		if (front == NULL)
			return;

		// Store previous front and
		// move front one node ahead
		QNode* temp = front;
		front = front->next;

		// If front becomes NULL, then
		// change rear also as NULL
		if (front == NULL)
			rear = NULL;

		delete (temp);
	}
};

 
int main()
{

	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front : " << ((q.front != NULL) ? (q.front)->data : -1)<< endl;
	cout << "Queue Rear : " << ((q.rear != NULL) ? (q.rear)->data : -1);
}
// This code is contributed by rathbhupendra

*/


//circular queue using linked list

/*
// C++ program for insertion and
// deletion in Circular Queue
#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
class Node {
    public:
	int data;
	struct Node* link;
};

class Queue {
    public:   
	class Node *front, *rear;
};

// Function to create Circular queue
void enQueue(Queue* q, int value)
{
	class Node* temp = new Node;
	temp->data = value;
	if (q->front == NULL)
		q->front = temp;
	else
		q->rear->link = temp;

	q->rear = temp;
	q->rear->link = q->front;
}

// Function to delete element from Circular Queue
int deQueue(Queue* q)
{
	if (q->front == NULL) {
		cout << "Queue is empty";
		return INT_MIN;
	}

	// If this is the last node to be deleted
	int value; // Value to be dequeued
	if (q->front == q->rear) {
		value = q->front->data;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else // There are more than one nodes
	{
		struct Node* temp = q->front;
		value = temp->data;
		q->front = q->front->link;
		q->rear->link = q->front;
		free(temp);
	}

	return value;
}

// Function displaying the elements of Circular Queue
void displayQueue(struct Queue* q)
{
	struct Node* temp = q->front;
	cout << endl << "Elements in Circular Queue are: ";
	while (temp->link != q->front) {
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << temp->data;
}

 
int main()
{
	// Create a queue and initialize front and rear
	Queue* q = new Queue;
	q->front = q->rear = NULL;

	// Inserting elements in Circular Queue
	enQueue(q, 14);
	enQueue(q, 22);
	enQueue(q, 6);

	// Display elements present in Circular Queue
	displayQueue(q);

	// Deleting elements from Circular Queue
	cout << endl << "Deleted value = " << deQueue(q);
	cout << endl << "Deleted value = " << deQueue(q);

	// Remaining elements in Circular Queue
	displayQueue(q);

	enQueue(q, 9);
	enQueue(q, 20);
	displayQueue(q);

	return 0;
}

*/






//Doubly que using Linked list

 // C++ implementation of Deque using
// doubly linked list
#include <bits/stdc++.h>

using namespace std;

// Node of a doubly linked list
struct Node {
	int data;
	Node *prev, *next;
	// Function to get a new node
	static Node* getnode(int data)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->prev = newNode->next = NULL;
		return newNode;
	}
};

// A structure to represent a deque
class Deque {
	Node* front;
	Node* rear;
	int Size;

public:
	Deque()
	{
		front = rear = NULL;
		Size = 0;
	}

	// Operations on Deque
	void insertFront(int data);
	void insertRear(int data);
	void deleteFront();
	void deleteRear();
	int getFront();
	int getRear();
	int size();
	bool isEmpty();
	void erase();
};

// Function to check whether deque
// is empty or not
bool Deque::isEmpty() { return (front == NULL); }

// Function to return the number of
// elements in the deque
int Deque::size() { return Size; }

// Function to insert an element
// at the front end
void Deque::insertFront(int data)
{
	Node* newNode = Node::getnode(data);
	// If true then new element cannot be added
	// and it is an 'Overflow' condition
	if (newNode == NULL)
		cout << "OverFlow\n";
	else {
		// If deque is empty
		if (front == NULL)
			rear = front = newNode;

		// Inserts node at the front end
		else {
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}

		// Increments count of elements by 1
		Size++;
	}
}

// Function to insert an element
// at the rear end
void Deque::insertRear(int data)
{
	Node* newNode = Node::getnode(data);
	// If true then new element cannot be added
	// and it is an 'Overflow' condition
	if (newNode == NULL)
		cout << "OverFlow\n";
	else {
		// If deque is empty
		if (rear == NULL)
			front = rear = newNode;

		// Inserts node at the rear end
		else {
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}

		Size++;
	}
}

// Function to delete the element
// from the front end
void Deque::deleteFront()
{
	// If deque is empty then
	// 'Underflow' condition
	if (isEmpty())
		cout << "UnderFlow\n";

	// Deletes the node from the front end and makes
	// the adjustment in the links
	else {
		Node* temp = front;
		front = front->next;

		// If only one element was present
		if (front == NULL)
			rear = NULL;
		else
			front->prev = NULL;
		free(temp);

		// Decrements count of elements by 1
		Size--;
	}
}

// Function to delete the element
// from the rear end
void Deque::deleteRear()
{
	// If deque is empty then
	// 'Underflow' condition
	if (isEmpty())
		cout << "UnderFlow\n";

	// Deletes the node from the rear end and makes
	// the adjustment in the links
	else {
		Node* temp = rear;
		rear = rear->prev;

		// If only one element was present
		if (rear == NULL)
			front = NULL;
		else
			rear->next = NULL;
		free(temp);

		// Decrements count of elements by 1
		Size--;
	}
}

// Function to return the element
// at the front end
int Deque::getFront()
{
	// If deque is empty, then returns
	// garbage value
	if (isEmpty())
		return -1;
	return front->data;
}

// Function to return the element
// at the rear end
int Deque::getRear()
{
	// If deque is empty, then returns
	// garbage value
	if (isEmpty())
		return -1;
	return rear->data;
}

// Function to delete all the elements
// from Deque
void Deque::erase()
{
	rear = NULL;
	while (front != NULL) {
		Node* temp = front;
		front = front->next;
		free(temp);
	}
	Size = 0;
}

// Driver program to test above
int main()
{
	Deque dq;
	cout << "Insert element '5' at rear end\n";
	dq.insertRear(5);

	cout << "Insert element '10' at rear end\n";
	dq.insertRear(10);

	cout << "Rear end element: " << dq.getRear() << endl;

	dq.deleteRear();
	cout << "After deleting rear element new rear"
		<< " is: " << dq.getRear() << endl;

	cout << "Inserting element '15' at front end \n";
	dq.insertFront(15);

	cout << "Front end element: " << dq.getFront() << endl;

	cout << "Number of elements in Deque: " << dq.size()
		<< endl;

	dq.deleteFront();
	cout << "After deleting front element new "
		<< "front is: " << dq.getFront() << endl;

	return 0;
}
