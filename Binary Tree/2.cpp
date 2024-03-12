#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
/*
 void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp-> data<< " ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
 }
 */

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//inorder
void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<< " ";
    inOrder(root->right);
}

//preorder
void preOrder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<< " ";
    preOrder(root->left);
    preOrder(root->right);
}

//postorder
void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<< " ";
}



int main()
{
    node *root = NULL;

    // creating a tree
    root = buildTree(root);

    // create levelordertravesal
    cout << "the level order traversal is " << endl;
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"Inorder: ";
    inOrder(root);
    cout<<endl;
    cout<<"preorder: ";
    preOrder(root);
    cout<<endl;
    cout<<"postorder: ";
    postOrder(root);
    cout<<endl;


    return 0;
}