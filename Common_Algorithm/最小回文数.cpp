// 分析可见：https://blog.csdn.net/cjllife/article/details/39938187
// 代码参考：https://blog.csdn.net/qq_45748941/article/details/107348091
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string findMinPalindrome(string s) {
        int n = s.size();
        int i;
        int flag = 0;
        for (i = n / 2 - 1; i >= 0; --i) {  // 中间往两边搜
            if (s[i] == s[n - 1 - i]) continue;
            if (s[i] > s[n - 1 - i]) flag = 1;
            break;
        }

        if (flag != 1) {  // 需要加 1
            int res = 0;
            for (int i = n / 2 - 1; i >= 0; --i) {
                ++s[i];
                if (s[i] > '9') {
                    s[i] = '0';
                    res = 1;
                    continue;
                }
                res = 0;
                break;
            }
            if (i == 0 && res == 1) {
                s.insert(s.begin(), '1');
            }
        }

        n = s.size();
        // 拼接出答案
        for (int i = n / 2 - 1; i >= 0; --i) {
            s[n - 1 - i] = s[i];
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.findMinPalindrome("44") << endl;
    return 0;
}