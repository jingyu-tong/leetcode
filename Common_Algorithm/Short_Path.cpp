//这部分总结一下最短路径相关的方法
//图表示为G(V, E)，V为顶点个数，E为边的个数

//Dijkstra
//Dijkstra可以求一个source到其他顶点的最短路径，但是图不能含有负权重
//Dijkstra我的理解就是贪心法，每次取当前最短的局部最优，也就是全局最优了
//从source开始，遍历所有到达的，有V个循环
//并且每次取出最小的同样还要遍历V次，复杂度为O(V^2 + E) = O(V^2)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //Dijkstra
        vector<vector<int>> graph(N + 1,vector<int>(N + 1,  -1));
         
        for(const auto& i : times) {
            graph[i[0]][i[1]] = i[2];
        }
         
        vector<int> dist(N + 1, INT_MAX);//路径长度
        vector<int> visited(N + 1, 0);
        dist[K] = 0;
        for(int i = 1; i <= N; ++i) {
            //找没访问过的最小值，O(V)
            int loc = 0;
            for(int j = 1; j <= N; ++j) {
                if(visited[j] == 0 && dist[j] < dist[loc])
                    loc = j;
            }
            if(dist[loc] == INT_MAX) break; //最小点仍然不可达，退出
            visited[loc] = 1;
            
            //更新，dist最多被更新E次
            for(int j = 1; j <= N; ++j) {
                if(graph[loc][j] == -1) continue;
                
                dist[j] = min(dist[j], dist[loc] + graph[loc][j]);
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//如果采用heap的话，复杂度为O(VlogV + ElogV) = O(logV(V + E))
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //Dijkstra
        vector<vector<int>> graph(N + 1,vector<int>(N + 1,  -1));
         
        for(const auto& i : times) {
            graph[i[0]][i[1]] = i[2];
        }
         
        vector<int> dist(N + 1, INT_MAX);//路径长度
        dist[K] = 0;
        priority_queue<pair<int, int>> q;//-长度，节点
        q.push({0, K});
        // vector<bool> visited(N + 1, false);//访问转态
        // visited[K] = true;
        while(!q.empty()) {
            auto ele = q.top(); q.pop();
            int t = ele.second; 
            //find the neighour
            for(int j = 1; j <= N; ++j) {//遍历t的所有边
                if(graph[t][j] == -1) continue;
                
                if(dist[j] > (dist[t] + graph[t][j])) {
                    dist[j] = dist[t] + graph[t][j];
                    q.push({-dist[j], j});
                }//更新 
            }
        }
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//Bellman-Ford 
//实际上是动态规划
//对于边edge(u, v)
//dp[v] = min(dp[v], dp[u] + w(edge(u, v)));
//那么对于每个顶点，每条边遍历，复杂度即为O(VE)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for(int i = 1; i <= N; ++i) {
            for(const auto& time : times) {
                int u = time[0];
                if(dist[u] == INT_MAX) continue;
                int v = time[1];
                dist[v] = min(dist[v], dist[u] + time[2]);
            }
        }
        
        int ans = INT_MIN;
        for(int i = 1; i <= N; ++i)
            ans = max(ans, dist[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};

//Floyd-Warshall
//其实也是动态规划
//dp(i, j, k)表示从i到j，只以[1,k]为中间节点的最短路径
//dp(i, j, k) = min(dp(i, j, k - 1), dp(i, k, k - 1) + dp(k, j, k - 1));
//上式表示用k个节点的最短路径是：不用第k个，和利用第k个进行跳转
//在原始空间迭代，空间复杂度可以降至二维
//时间复杂度O(V^3)
// Floyd-Warshall
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Floyd-Warshall actually it is DP
        const int kMaxElement = 101 * 100;
        vector<vector<int>> dp(N, vector<int>(N, kMaxElement));
         
        for(const auto& time : times) {
            dp[time[0] - 1][time[1] - 1] = time[2];
        }
        for(int i = 0; i < N; ++i)
            dp[i][i] = 0;
        for(int k = 0; k < N; ++k) {
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            if(dp[K - 1][i] >= kMaxElement) return -1;
            ans = max(ans, dp[K - 1][i]);
        }
        return ans;
    }
};




