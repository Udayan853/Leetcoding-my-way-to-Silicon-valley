class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        map <char, char> relationMap = {{')', '('}, {'}', '{'}, {']', '['}};
        for(char ch:s){
            switch(ch){
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                case ']':
                case '}':
                    if(st.empty() || relationMap[ch] != st.top()) return false;
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};