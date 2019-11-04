class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0) {
                ans = i + 1;
                sum = 0;
            }
        }
        return total < 0 ? -1 : ans;
    }
};
