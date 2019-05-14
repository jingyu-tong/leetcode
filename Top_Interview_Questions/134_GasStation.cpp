class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, ans = 0;
        for(int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0) {
                sum = 0;
                ans = i + 1;//之前的都不为起点
            }
        }
        return total < 0 ? -1 : ans;
    }
};