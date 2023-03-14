class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10==0 && x!=0)) return false;
        if(x == 0) return true;

        long int tmp = x, soln = 0;
        while(x>0){
            if(soln>=tmp){
                break;
            }
            soln = 10*soln + x % 10;
            x = x/10;
        }
        return tmp == soln;
    }
};