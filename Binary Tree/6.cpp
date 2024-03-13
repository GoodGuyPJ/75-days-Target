check for balanced height of binary tree
// approach 1
class Solution{
     int height(struct Node* node){
        if(node == nullptr){
            return 0;
        }
        int left = height(node->left);
        int right  = height(node->right);
        
        int ans = max(left, right)+1;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root ==0 ){
            return 0;
        }
        
        bool left =isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root->right)) <=1;
        
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};



// approach 2
class Solution{
     int height(struct Node* node){
        if(node == nullptr){
            return 0;
        }
        int left = height(node->left);
        int right  = height(node->right);
        
        int ans = max(left, right)+1;
        return ans;
    }
    
    pair<int, int> isBalancedFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int, int> left = isBalancedFast(root->left);
        pair<int, int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns= right.first;
        
        bool diff =  abs(left.second - right.second) <=1;
        
        pair<bool, int> ans;
        ans.second = max(left.second, right.second)+1;
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};