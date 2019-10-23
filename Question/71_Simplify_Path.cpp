// .. 删掉上个路径
// . 直接无视
// 多个//保留一个
// 空 返回/
class Solution {
public:
    string simplifyPath(string path) {
        string ans, t;
        stringstream ss(path);
        vector<string> mem;
        while(getline(ss, t, '/')) {
            if(t == "" || t == ".") continue;
            if(t == ".." && !mem.empty()) mem.pop_back();
            else if(t != "..") mem.push_back(t);
        }
        for(auto& ele : mem) ans += "/" + ele;
        return ans.empty() ? "/" : ans;
    }
};
