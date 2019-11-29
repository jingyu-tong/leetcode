class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        
        int loc = 0;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == ' ') {
                reverse(str.begin() + loc, str.begin() + i);
                loc = i + 1;
            }
        }
        reverse(str.begin() + loc, str.end());
        return str;
    }
};