// check sum tree

class Solution
{
    public:
    pair<bool, int> isSumTreeFast(Node* root){
        if(root ==NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        
        
        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);
        
        bool isleftsumtree = leftAns.first;
        bool isrightsumtree = rightAns.first;
        
        int leftSum  = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        if(isleftsumtree && isrightsumtree && condn){
            ans.first = true;
            ans.second = 2* root->data;
            // ans.second = root->data+leftSum +rightSum;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
        
    }
};