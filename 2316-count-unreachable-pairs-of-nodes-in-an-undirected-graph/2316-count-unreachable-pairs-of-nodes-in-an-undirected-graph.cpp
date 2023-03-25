class Solution {
public:
    int dfs(int node, vector<vector<int>> &graph, vector<bool> &vis){
      if(vis[node]) return 0;
      int res = 1;
      vis[node] = true;
      for(auto &adj: graph[node]){
        if(!vis[adj]){
          res += dfs(adj, graph, vis);
        } 
      }
      return res;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
      vector<bool> vis(n, false);
      vector<vector<int>> graph(n);
      for(auto &e: edges){
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
      }
      long long ans = 0, compSize = 0, remaining = n;
      for(int i = 0; i < n; i++){
        if(!vis[i]){
          compSize = dfs(i, graph, vis);
          ans += compSize * (remaining - compSize);
          remaining -= compSize;
        }
      }
      return ans;
    }
};