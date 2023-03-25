class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int itr1 = 0, itr2 = 1;
        while(itr2 < nums.size()){
            while(nums.size() > itr2 && nums[itr1] == nums[itr2]) itr2++;
            if(itr2 >= nums.size()) break;
            itr1++;
            nums[itr1] = nums[itr2];
            itr2++;
        }
        return itr1 + 1;
    }
};