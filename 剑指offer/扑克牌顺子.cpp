class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false;
        
        sort(numbers.begin(), numbers.end());
        int count_zero = 0;
        for(auto& num : numbers) {
            if(num == 0) ++count_zero;
        }
        
        for(int i = count_zero; i < numbers.size() - 1; ++i) {
            int gap = numbers[i + 1] - numbers[i];
            if(gap == 0) return false;
            if(gap - 1 == 0) continue;
            count_zero = count_zero - gap + 1;
            if(count_zero < 0) return false;
        }
        return true;
    }
};