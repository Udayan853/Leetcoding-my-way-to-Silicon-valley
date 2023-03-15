class Solution {
public:
    int LIS(vector<int> &nums, vector <int> &cache, int indx){
        if(cache[indx] != -1) return cache[indx];
        if(indx == nums.size() - 1){
            cache[indx] = 1;
            return 1;
        }
        int maxSize = 1;
        for(int i = indx + 1; i < nums.size(); i++){
            if(nums[indx] < nums[i]){
                maxSize = max(maxSize, LIS(nums, cache, i) + 1);
            }
        }
        cache[indx] = maxSize;
        return maxSize;
    }

    int lengthOfLIS(vector<int>& nums) {
        int maxSz = -1;
        vector <int> cache(nums.size(), -1);
        for(int i = nums.size() - 1; i >= 0; i--){
            maxSz = max(maxSz, LIS(nums, cache, i));
        }
        return maxSz;
    }
};
