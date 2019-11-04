//bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mem; //old, new
        return bfs(node, mem);
    }
    Node* bfs(Node* node, unordered_map<Node*, Node*>& mem) {
        if(!node) return node;

        queue<Node*> q;
        q.push(node);
        Node* dummy = new Node(node->val);
        mem[node] = dummy;
        while(!q.empty()) {
            Node* t = q.front(); q.pop();
            for(auto& ele : t->neighbors) {
                if(mem.count(ele) == 0) {
                    mem[ele] = new Node(ele->val);
                    q.push(ele);
                }
                mem[t]->neighbors.push_back(mem[ele]);
            }
        }
        return dummy;
    }
};
//dfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mem; //old, new
        return dfs(node, mem);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mem) {
        if(!node) return node;
        if(mem.count(node)) return mem[node];

        mem[node] = new Node(node->val);
        for(auto& ele : node->neighbors) {
            mem[node]->neighbors.push_back(dfs(ele, mem));
        }
        return mem[node];
    }
};
