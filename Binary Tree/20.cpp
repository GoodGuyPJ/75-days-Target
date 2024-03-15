Kth Ancestor in a Tree
approach 1
Node* solve(Node* root, int k, int node, vector<int>& path, int &ans){
    if(root == NULL)
     return NULL;
    
    path.push_back(root->data);
    if(root -> data == node)
    return root ;
    
    
  Node* left=  solve(root->left, k, node, path, ans);
  Node* right= solve(root->right, k, node, path, ans);
    
    if(left !=NULL || right !=NULL){
        int size = path.size();
    
    for(int i=0;i<path.size();i++){
        if(path[i] == node){
            int index = i-k;
            
            if(index<0)
                return NULL;
            
            else
                ans = path[i-k];
                

        }
    }
    }
     else{
    path.pop_back();
         return NULL;
         
     }
    
}
int kthAncestor(Node *root, int k, int node)
{  
    if(root->data == node) return -1;
    vector<int> path;
    int ans = -1;
      solve(root, k, node, path, ans);
    return ans;
}







approach 2
Node* solve(Node *root, int &k, int node){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data == node){
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns ==NULL){
        k--;
        if(k<=0){
            k= INT_MAX;
            return root;
        }
        return leftAns;
    }
    
     if(leftAns == NULL && rightAns !=NULL){
        k--;
        if(k<=0){
            k= INT_MAX;
            return root;
        }
        return rightAns;
    }
    
    return NULL;
    
}

int kthAncestor(Node *root, int k, int node)
{
     Node* ans = solve(root, k, node);
     if(ans == NULL || ans->data == node){
         return -1;
     }
     else{
         return ans->data;
     }
}
