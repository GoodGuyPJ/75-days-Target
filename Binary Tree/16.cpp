//Diagonal Traversal of Binary Tree

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root ==NULL) return ans;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        while(curr!=NULL){
            if(curr->left !=NULL){
                q.push(curr->left);
            }
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}