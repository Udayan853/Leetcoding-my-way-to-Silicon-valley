class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int middleElem, tmpIter;
        string soln = "";
        for(int i = 0; i < numRows; i++){
            tmpIter = i;
            while(tmpIter < s.size()){
                soln += s.at(tmpIter);
                middleElem = tmpIter + 2*(numRows - 1) - 2*i;
                if((i != 0) && (i != numRows-1) && (s.size() > middleElem)){
                    soln += s.at(middleElem);
                }
                tmpIter = tmpIter + 2*(numRows - 1);
            }
        }
        return soln;
    }
};