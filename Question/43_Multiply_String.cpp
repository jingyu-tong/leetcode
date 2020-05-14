// n位整数 m位整数
// i j位相乘的权重为i + j - 1
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";

        const int m = num1.size();
        const int n = num2.size();
        vector<int> ans_int(m + n);  // 从高位到低位

        // 从低位开始计算
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int multi = (num1[i] - '0') * (num2[j] - '0');
                int ind = i + j;
                int sum = multi + ans_int[ind + 1];
                ans_int[ind + 1] = sum % 10;  //低位
                ans_int[ind] +=
                    sum / 10;  // 高位，这里不用管，因为之后会一直进位到顶的
            }
        }

        string ans;
        for (int ele : ans_int) {
            if (!ans.empty() || ele != 0) ans.push_back(ele + '0');
        }
        return ans.empty() ? "0" : ans;
    }
};
