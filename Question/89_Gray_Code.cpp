//二进制+1时，每次最多只有一个相邻bit的异或值改变
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;

        for(int i = 0; i < pow(2, n); ++i) {
            ans.push_back(i >> 1 ^ i);
        }
        return ans;
    }
};
