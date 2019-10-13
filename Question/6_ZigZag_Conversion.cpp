class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;

        vector<string> vec(numRows);
        int i = 0;
        int length = s.size();
        while(i < length) {
            //column first
            for(int j = 0; j < numRows && i < length; ++j) {
                vec[j] += s[i++];
            }
            //row
            for(int j = numRows - 2; j > 0 && i < length; --j) {
                vec[j] += s[i++];
            }
        }
        string ans;
        for(auto& ele : vec) ans += ele;
        return ans;
    }
};
