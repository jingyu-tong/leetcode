//从左下角开始search
//从右上角也可
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0 || array[0].size() == 0) return false;
        
        const int m = array.size(); 
        const int n = array[0].size();
        int ind_x = m - 1;
        int ind_y = 0;
        while(ind_x >= 0 && ind_x < m && ind_y >= 0 && ind_y < n) {
            if(target == array[ind_x][ind_y]) return true;
            if(target < array[ind_x][ind_y]) {
                --ind_x;
            } else {
                ++ind_y;
            }
        }
        return false;
    }
};