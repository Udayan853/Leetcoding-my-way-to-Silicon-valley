class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ptr1, ptr2, ans, calcSum;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            ptr1 = i + 1;
            ptr2 = nums.size() - 1;
            while(ptr1 < ptr2){
                calcSum = nums[ptr1] + nums[ptr2] + nums[i];
                if(calcSum == target) return calcSum;
                else if(minDiff > abs(target - calcSum)){
                    minDiff = abs(target - calcSum);
                    ans = calcSum;
                }
                (calcSum < target)?ptr1++:ptr2--;
            }
        }
        return ans;
    }
};