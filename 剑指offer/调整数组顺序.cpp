//bubble sort like
//O(n^2)
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        const int n = array.size();
        for(int i = 0; i < n; ++i) {
            if(array[i] % 2 == 1) continue;
            for(int j = n - 1; j > i; --j) {
                if(array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                    swap(array[j], array[j - 1]);
            }
        }
    }
};