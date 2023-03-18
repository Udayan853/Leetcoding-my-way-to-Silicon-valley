class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int soln = 0, tmp = abs(x);
        while(tmp > 0){
            if(soln <= INT_MAX/10){
                soln = 10*soln + tmp%10;
                tmp /= 10;
            }
            else{
                return 0;
            }
        }
        return (x<0)?-soln:soln;
    }
};