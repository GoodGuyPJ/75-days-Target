void createMapping(int in[], map<int, int> &nodeToIndex, int n){
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
    //base case
    if(index <0 || inOrderStart>inOrderEnd){
        return NULL;
    }
    
    int element = post[index--];
    Node* root = new Node(element);
    
    int position = nodeToIndex[element];
    
    root->right = solve(in, post,  index, position+1, inOrderEnd, n, nodeToIndex);
    root->left = solve(in, post,  index, inOrderStart, position-1, n, nodeToIndex);
         
         return root;
    
    
}


Node *buildTree(int in[], int post[], int n) {
     int postOrderIndex = n-1;
     map<int, int> nodeToIndex;
     createMapping(in, nodeToIndex, n);
     
     Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
     return ans;
     
}