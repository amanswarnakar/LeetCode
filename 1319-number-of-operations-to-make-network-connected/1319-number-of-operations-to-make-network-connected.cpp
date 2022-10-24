class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int currNode){
      vis[currNode] = true;
      for(int node : graph[currNode]){
        if(!vis[node])  dfs(graph, vis, node);
      }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
      int m = v.size();
      if(m < n - 1) return -1;
      int ans = 0;
      vector<bool> vis(n, false);
      vector<vector<int>> graph(n);
      for(auto edge : v){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }
      for(int i = 0; i < n; i++){
        if(!vis[i]){
          ans++;
          dfs(graph, vis, i);
        }
      }
      return ans - 1;
    }
};