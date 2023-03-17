class Solution {
public:
    bool isPalindromicSubstr(string &s, vector<vector<int> > &cache, int start, int end){
        if(cache[start][end] != -1) return cache[start][end]; 
        else if(end == start) return cache[start][end] = 1;
        else if(end - start == 1) return cache[start][end] = s.at(start) == s.at(end);
        else if(s.at(start) == s.at(end)){
            if(cache[start+1][end-1] < 0)
                return cache[start][end] = isPalindromicSubstr(s, cache, start + 1, end - 1);
            return cache[start + 1][end - 1];
        }
        else return 0;
    }

    string longestPalindrome(string s) {
        vector<vector<int> > cache(s.size() , vector<int> (s.size(), -1));
        int maxSize = 1;
        int indx1 = 0, indx2 = 0;
        cout<<s.size()<<"\n";
        for(int i = 0; i < s.size() - 1; i++){
            for(int j = i + 1; j < s.size(); j++){
                if(isPalindromicSubstr(s, cache, i, j) && j - i + 1> maxSize){
                    maxSize = j - i + 1;
                    indx1 = i, indx2 = j;
                }
            }
        }
        return s.substr(indx1, maxSize);
    }
};