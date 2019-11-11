class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cur1 = 0;
        int cur2 = 0;
        while(cur1 < version1.size() && cur2 < version2.size()) {
            //search ver1
            int point1;
            for(point1 = cur1; point1 < version1.size(); ++point1) {
                if(version1[point1] == '.') break;
            }
            string str1 = version1.substr(cur1, point1 - cur1);
            cur1 = point1 == version1.size() ? point1 : point1 + 1;

            //search ver2
            int point2;
            for(point2 = cur2; point2 < version2.size(); ++point2) {
                if(version2[point2] == '.') break;
            }
            string str2 = version2.substr(cur2, point2 - cur2);
            cur2 = point2 == version2.size() ? point2 : point2 + 1;

            int num1 = stoi(str1);
            int num2 = stoi(str2);
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
        }
        if(cur1 == version1.size() && cur2 == version2.size()) return 0;

        string str = cur1 == version1.size() ? version2.substr(cur2) : version1.substr(cur1);
        for(auto& ele : str) {
            if(ele == '.') continue;
            if(ele != '0') return cur1 == version1.size() ? -1 : 1;
        }
        return 0;
    }
};
