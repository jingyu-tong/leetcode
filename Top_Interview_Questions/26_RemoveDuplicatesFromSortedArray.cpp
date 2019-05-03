/*
**就地覆盖，不删除
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        int last = nums[0], last_loc = 0;//储存上一次的值
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == last) {
                --n;
                continue;
            }
            ++last_loc;
            nums[last_loc] = nums[i];
            last = nums[i];
            
        }
        return n;
    }
};
/*
**另一种更简洁的写法
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //注意边界
        if(nums.size() == 0) return 0;
        //采用下标直接访问,不删除，直接覆盖
        int pre=0,cur=0;
        while(cur < nums.size()){
            if(nums[pre] == nums[cur]) ++cur;
            else nums[++pre] = nums[cur++];
        }
        return pre+1;
    }
};