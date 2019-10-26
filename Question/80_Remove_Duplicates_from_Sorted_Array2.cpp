class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int left  = 0;
        int cur = 0;
        int count = 0;
        while(cur < length) {
            if(nums[cur] == nums[left])
                ++count;
            else {
                if(count > 2) { //往前移
                    for(int i = cur; i < length; ++i) {
                        nums[left + 2 + i - cur] = nums[i];
                    }
                    length = length - (count - 2);
                    cur = left + 2;
                }
                count = 1;
                left = cur;
            }
            ++cur;
        }
        if(count > 2) length = length - (count - 2);  //末尾重复
        return length;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int left = 0;
        int cur = 1;
        int count = 1;
        while(cur < nums.size()) {
            if(nums[cur] == nums[left] && count == 2) ++cur; //直接跳掉
            else {
                if(nums[cur] == nums[left]) ++count;
                else count = 1;
                nums[++left] = nums[cur++];
            }
        }
        return left + 1;
    }
};
