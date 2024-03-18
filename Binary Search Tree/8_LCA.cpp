//lowest common factor

//recursive approach
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
     if(root == NULL){
         return nullptr;
     }

     if(root->data <P->data && root->data <Q->data){
         return LCAinaBST(root->right, P, Q);
     }
     if(root->data > P->data && root->data > Q->data){
         return LCAinaBST(root->left, P, Q);
     }
     return root;
}

// itrative approch
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    while(root!=NULL){
        if(root->data <P->data && root->data <Q->data){
            root = root->right;
        }
        if(root->data > P->data && root->data > Q->data){
            root= root->left;
        }
        else{
           return  root ;
        }
    }