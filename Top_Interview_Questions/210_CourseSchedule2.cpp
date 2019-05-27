class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph_ = vector<vector<int>>(numCourses);
        for(auto i : prerequisites) 
            graph_[i[0]].push_back(i[1]);
        
        vector<int> visited(numCourses, 0);
        vector<int> ans;
        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(i, visited, ans)) return {};
        }
        return ans;
    }
private:
    vector<vector<int>> graph_;
    bool dfs(int loc, vector<int>& visited, vector<int>& ans) {
        if(visited[loc] == 1) return false;
        if(visited[loc] == 2) return true;
        
        visited[loc] = 1;
        for(auto i : graph_[loc]) {
            if(!dfs(i, visited, ans)) return false;
        }
        visited[loc] = 2;
        ans.push_back(loc);
        return true;
    }
};