class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty()) return {};
        
        auto compare = [](int x, int y) {
            return to_string(x) + to_string(y) < to_string(y) + to_string(x);
        };
        sort(numbers.begin(), numbers.end(), compare);
        
        string ans;
        for(int i = 0; i < numbers.size(); ++i) {
            ans += to_string(numbers[i]);
        }
        return ans;
    }
};