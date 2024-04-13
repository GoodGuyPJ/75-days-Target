class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            int remaning  = target - nums[i];
            if(mpp.find(remaning) != mpp.end()){
                return {mpp[remaning], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};