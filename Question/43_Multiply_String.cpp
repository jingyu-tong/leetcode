//n位整数 m位整数
//i j位相乘的权重为i + j - 1
class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        int n = num1.size();
        int m = num2.size();
        vector<int> ans_vec(n + m); //高到低

        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                int mul_res = (num1[i] - '0') * (num2[j] - '0');
                int ind = i + j;
                int sum = mul_res + ans_vec[ind + 1];
                ans_vec[ind] += sum / 10;
                ans_vec[ind + 1] = sum % 10;
            }
        }
        for (int ele : ans_vec) {
            if (!ans.empty() || ele != 0) ans.push_back(ele + '0');
        }
        return ans.empty() ? "0" : ans;
    }
};
