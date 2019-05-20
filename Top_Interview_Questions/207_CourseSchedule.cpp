class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph_ = vector<vector<int>>(numCourses);
        
        for(auto i : prerequisites)
            graph_[i.first].push_back(i.second);
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; ++i)
            if(dfs(i, visited)) return false;
        return true;
    }
private:
    vector<vector<int>> graph_;
    bool dfs(int cur, vector<int>& visited) {
        if(visited[cur] == 1) return true;
        if(visited[cur] == 2) return false;
        
        visited[cur] = 1;
        for(auto i : graph_[cur]) {
            if(dfs(i, visited)) return true;
        }
        visited[cur] = 2;
        return false;
    }
};
};
