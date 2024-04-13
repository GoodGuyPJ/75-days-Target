bol
class Solution {
public:
     

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n =strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for(int i=0; i<n; i++){
            string word = strs[i];

            string new_word = generate(word);
            mp[new_word].push_back(word);
        }
        for(auto &it: mp){
            result.push_back(it.second);
        }
        

        return result;
    }
};
