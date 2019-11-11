class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator);
        long long den = abs( (long long)denominator);

        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string ans = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) ans = "-" + ans;
        if (rem == 0) return ans;
        ans += '.';
        string demical;
        int pos = 0;
        while(rem != 0) {
            //is in hashmap
            if(m.find(rem) != m.end()) {
                demical.insert(m[rem], "(");
                demical += ")";
                return ans + demical;
            }
            m[rem] = pos;
            demical += to_string((rem * 10) / den);
            rem = rem * 10 % den;
            ++pos;
        }
        return ans  + demical;
    }
};
