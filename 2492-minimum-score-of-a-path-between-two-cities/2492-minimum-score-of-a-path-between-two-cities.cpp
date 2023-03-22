class Solution {
public:
    void dfs(vector<vector<pair<int, int>>> &graph, int node, vector<bool> &vis, int &ans){
      if(vis[node]) return;
      vis[node] = true;
      for(auto &[adj, dist]: graph[node]){
        ans = min(ans, dist);
        if(!vis[adj]) dfs(graph, adj, vis, ans);
      }
    }
    int minScore(int n, vector<vector<int>>& roads) {
      vector<vector<pair<int, int>>> graph(n);
      for(auto &road: roads){
        graph[road[0] - 1].emplace_back(make_pair(road[1] - 1, road[2]));
        graph[road[1] - 1].emplace_back(make_pair(road[0] - 1, road[2]));
      }
      vector<bool> vis(n, false);
      int ans = INT_MAX;
      dfs(graph, 0, vis, ans);
      return ans;
    }
};