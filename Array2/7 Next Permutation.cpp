class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
         int golo_index = -1;
         for(int i=n-2; i>=0; i--){
            if(nums[i] <nums[i+1]){
                golo_index = i;
                break;
            }
         }

         if(golo_index!= -1){
            for(int i=n-1; i>golo_index; i--){
                if(nums[i] > nums[golo_index]){
                    swap(nums[i], nums[golo_index]);
                    break;
                }
            }
         }
         reverse(nums.begin()+golo_index+1, nums.end());
    }
};