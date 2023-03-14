class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int midVal = (m + n)/2;

        int l = 0, r = m - 1;
        int i = 0, j = 1;
        while(true){
            i = floor(((float)l + (float)r)/2);
            j = midVal - i - 2;

            int leftA = (i >= 0)? nums1[i]:INT_MIN;
            int leftB = (j >= 0)? nums2[j]:INT_MIN;
            int rightA = (i + 1 < m)?nums1[i + 1]:INT_MAX;
            int rightB = (j + 1 < n)?nums2[j + 1]:INT_MAX;

            if(leftA <= rightB && leftB <= rightA){
                if ((m+n)%2){
                    return min(rightA, rightB);
                }
                return ((double)min(rightA, rightB) + (double)max(leftA, leftB))/2;
            }
            
            else if (leftA > rightB){
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }

        return 0.0;
    }
};