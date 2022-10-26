class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<vector<int>> &outgoing, int cn, int caller, int &ans){
      vis[cn] = true;
      if(caller != -1){
        if(find(outgoing[cn].begin(), outgoing[cn].end(), caller) == outgoing[cn].end())
          ans++;
      }
      for(auto &node : graph[cn]){
        if(!vis[node])
          dfs(graph, vis, outgoing, node, cn, ans);
      }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
      int ans = 0;
      vector<bool> vis(n, false);
      vector<vector<int>> graph(n);
      vector<vector<int>> outgoing(n);
      for(auto &con : connections){
        graph[con[0]].emplace_back(con[1]);
        graph[con[1]].emplace_back(con[0]);
        outgoing[con[0]].emplace_back(con[1]);
      }
      dfs(graph, vis, outgoing, 0, -1, ans);
      return ans;
    }
};