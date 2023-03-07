class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int maxLen = 0;
        int ptr1 = 0; int ptr2 = 0;
        set <char> elements;

        while(ptr2 < s.length()){
            if(!elements.count(s.at(ptr2))){
                elements.insert(s.at(ptr2));
                ptr2++;
            }
            else{
                if(ptr1 == ptr2){
                    elements.erase(s.at(ptr1));
                    ptr2++; ptr1++;
                    elements.insert(s.at(ptr1));
                }
                else{
                    elements.erase(s.at(ptr1));
                    ptr1++;
                }
            }
            maxLen = maxLen < elements.size()?elements.size():maxLen;
        }
        return maxLen;
    }
};