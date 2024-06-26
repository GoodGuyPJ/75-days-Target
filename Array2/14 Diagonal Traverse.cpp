class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        map<int, vector<int>> mp;
        vector<int> result;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip = true;
        for(auto& it:mp){
            if(flip) reverse(it.second.begin(), it.second.end());
        
        for(auto & nums:it.second){
            result.push_back(nums);
        }
        flip = !flip;
        }
        return result;
    }
};