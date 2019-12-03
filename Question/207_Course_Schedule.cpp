class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses <= 0) return true;
        
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        for(auto& ele : prerequisites) {
            for(int i = 1; i < ele.size(); ++i) {
                graph[ele[0]][ele[i]] = 1;
            }
        }
        
        //拓扑排序
        vector<int> visited(numCourses, 0); //1在上 2上完了
        for(int i = 0; i < numCourses; ++i) {
            if(dfs(graph, i, visited)) return false;
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph, int cur, vector<int>& visited) {
        if(visited[cur] == 1) return true;
        if(visited[cur] == 2) return false;
        
        visited[cur] = 1;
        for(int i = 0; i < graph[cur].size(); ++i) {
            if(graph[cur][i] == 0) continue;
            if(dfs(graph, i, visited)) return true;
        }
        visited[cur] = 2;
        return false;
    }
};