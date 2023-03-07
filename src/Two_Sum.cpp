class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;

        for(int i = 0; i<nums.size(); i++){
            int complementVal = target - nums[i];
            if(um.count(complementVal) > 0){
                return {um[complementVal], i};
            }
            um[nums[i]] = i;
        }
        return {};
    }    
};