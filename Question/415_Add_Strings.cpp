class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? num1[m--] - '0' : 0;
            int q = n >= 0 ? num2[n--] - '0' : 0;
            int sum = p + q + carry;
            ans = to_string(sum % 10) + ans;
            carry = sum / 10;
        }

        if (carry) ans = to_string(carry) + ans;

        return ans;
    }
};

// 这里利用右值，可以大大缩小需要的内存，想加速的话，可以反过来存再
// reverse，速度会快很多
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? num1[m--] - '0' : 0;
            int q = n >= 0 ? num2[n--] - '0' : 0;
            int sum = p + q + carry;
            string num = to_string(sum % 10);
            ans = num + move(ans);
            carry = sum / 10;
        }

        if (carry) ans = to_string(carry) + ans;

        return ans;
    }
};