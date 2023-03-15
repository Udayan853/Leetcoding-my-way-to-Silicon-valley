class Solution {
public:
    int romanToInt(string s) {
        map <char, int> hashMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int solution = 0, nextVal = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if( hashMap[s.at(i)] >= nextVal ){
                solution += hashMap[s.at(i)];
            }
            else{
                solution -= hashMap[s.at(i)];
            }
            nextVal = hashMap[s.at(i)];
        }
        return solution;
    }
};