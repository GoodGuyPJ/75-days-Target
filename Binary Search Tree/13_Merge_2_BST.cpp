/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode *root, vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size()+b.size());
    int i=0, j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i]; 
            i++;
        }
        else{
            ans[k++] =b[j];
            j++;
        }
    }

    while(i<a.size()){
         ans[k++] = a[i];
            i++;
    }

    while(j<b.size()){
                    ans[k++] =b[j];
            j++;

    }
    return ans;
}

TreeNode * inorderToBST(int s, int e, vector<int> &in){
    //base case
    if(s>e) return NULL;
    int mid = s+(e-s)/2;
    TreeNode  *root = new TreeNode (in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);
    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // step1 store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    //step 2 merge2 sorted array
    vector<int> mergeArray = mergeArrays(bst1, bst2);

    //step 3 inorder to BST 
    int s = 0, e = mergeArray.size()-1;
    // return inorderToBST(s, e, mergeArray);

    return mergeArray;


}