class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1;
        int n = b.size() - 1;
        int flag = 0;
        string ans = "";
        while(m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0 ;
            int sum = p + q + flag;
            ans = to_string(sum % 2) + ans;
            flag = sum / 2;
        }
        if(flag == 1) ans = "1" + ans;

        return ans;
    }
};
