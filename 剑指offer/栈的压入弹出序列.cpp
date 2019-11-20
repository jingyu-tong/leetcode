//这里我用了栈，我感觉应该可以不用？
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()) return true;
        
        int cur1 = 0;
        int cur2 = 0;
        stack<int> s;
        while(cur1 < pushV.size()) {
            if(pushV[cur1] != popV[cur2]) {
                s.push(pushV[cur1]);
            } else {
                ++cur2;
            }
            ++cur1;
        }
        
        while(!s.empty()) {
            int temp = s.top();
            if(temp != popV[cur2]) return false;
            s.pop();
            ++cur2;
        }
        return true;
    }
};