class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string common = strs[0];
        for(int i = 1; i < strs.size(); i++){
            if(common.compare(strs[i]) != 0){
                for(int j = 0; j < common.size(); j++){
                    if(common.at(j) != strs[i].at(j)){
                        common = common.substr(0, j);
                        break;
                    }
                }
            }
        }
        return common;
    }
};