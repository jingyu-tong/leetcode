//因为要输出上课先后顺序，注意push位置
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses <= 0) return {};
        
        vector<vector<int>> graph(numCourses);
        for(auto& ele : prerequisites) {
            graph[ele[0]].push_back(ele[1]);
        }
        
        vector<int> visited(numCourses, 0);
        vector<int> ans;
        for(int i = 0; i < numCourses; ++i) {
            vector<int> cur;
            if(dfs(graph, i, visited, cur)) return {};
            for(int i = 0; i < cur.size(); ++i)
                ans.push_back(cur[i]);
        }
        return ans;
    }
private:
    bool dfs(vector<vector<int>>& graph, int cur, vector<int>& visited, vector<int>& ans) {
        if(visited[cur] == 1) return true;
        if(visited[cur] == 2) return false;
        
        visited[cur] = 1;
        for(auto& ele : graph[cur]) {
            if(dfs(graph, ele, visited, ans)) return true;
        }
        ans.push_back(cur);
        visited[cur] = 2;
        
        return false;
    }
};