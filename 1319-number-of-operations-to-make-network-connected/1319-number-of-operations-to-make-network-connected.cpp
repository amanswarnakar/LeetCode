class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int currNode){
      vis[currNode] = true;
      for(auto &node: graph[currNode]){
        if(!vis[node])
          dfs(graph, vis, node);
      }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      int m = connections.size(), ans = -1;
      if(m < n - 1) return ans;
      vector<bool> vis(n, false);
      vector<vector<int>> graph(n);
      for(auto con: connections){
        graph[con[0]].emplace_back(con[1]);
        graph[con[1]].emplace_back(con[0]);
      }
      for(int i = 0; i < n; i++){
        if(!vis[i])
          dfs(graph, vis, i), ans++;
      }
      return ans;
    }
};