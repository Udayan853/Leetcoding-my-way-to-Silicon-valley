class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > solution;
        sort(nums.begin(), nums.end());

        int target_indx = 0, lo, hi;
        int prev_indx, prev_lo, prev_hi;

        do{
            prev_indx = target_indx;
            lo = target_indx + 1;
            hi = nums.size() - 1;
            prev_lo = -1;
            prev_hi = -1;

            while(lo < hi){
                if(prev_lo != -1 && prev_hi != -1){
                    while(lo < hi && nums[prev_lo] == nums[lo] && nums[prev_hi] == nums[hi]){
                        lo++;hi--;
                    }
                    if(lo >= hi) break;
                }
                if(nums[lo] + nums[hi] + nums[target_indx] == 0){
                    solution.push_back({nums[target_indx], nums[lo], nums[hi]});
                    prev_lo = lo++;
                    prev_hi = hi--;
                }
                else if(nums[lo] + nums[hi] < -nums[target_indx]) lo++;
                else hi--;
            }
            while(target_indx < nums.size() - 2 && nums[target_indx] == nums[prev_indx]) target_indx++;
        }while(target_indx < nums.size() - 2);
        return solution;
    }
};