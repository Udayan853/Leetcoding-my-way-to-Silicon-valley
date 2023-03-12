class Solution {
public:
    int xorOperation(int n, int start) {
        int soln = start;
        int end = 2*(n-1) + start;
        start += 2;
        while(start <= end){
            soln ^= start;
            start += 2;
        }
        return soln;
    }
};