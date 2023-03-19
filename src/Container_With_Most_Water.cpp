class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int maxSize = 0;
        while(start < end){
            maxSize = max(min(height[start], height[end])* (end - start), maxSize);
            height[start] < height[end]?start++:end--;
        }
        return maxSize;
    }
};