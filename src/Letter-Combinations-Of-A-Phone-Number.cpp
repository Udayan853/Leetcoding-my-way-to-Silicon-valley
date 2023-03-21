class Solution {
public:
    vector <string> getCombiVec(string &digits, map <int, vector<string> > &hashMap, vector <string> &prevVec, int pos){
        if(pos >= digits.size()) return prevVec;
        int curDigit = digits.at(pos) - '0';
        vector <string> soln;

        for(string s:prevVec){
            for(int i = 0; i < hashMap[curDigit].size(); i++){
                soln.push_back(s+hashMap[curDigit][i]);
            }
        }
        return getCombiVec(digits, hashMap, soln, ++pos);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        map <int, vector <string> > hashMap = {
            {2, {"a", "b", "c"}},
            {3, {"d", "e", "f"}},
            {4, {"g", "h", "i"}},
            {5, {"j", "k", "l"}},
            {6, {"m", "n", "o"}},
            {7, {"p", "q", "r", "s"}},
            {8, {"t", "u", "v"}},
            {9, {"w", "x", "y", "z"}}
        };

        return getCombiVec(digits, hashMap, hashMap[digits.at(0) - '0'], 1);
    }
};