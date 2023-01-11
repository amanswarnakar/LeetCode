class Solution {
public:
    int dfs(int node, int time, vector<vector<int>> &graph, vector<bool> &apple, vector<bool> &vis){
      if(vis[node]) return 0;
      vis[node] = true;
      int temp = 0;
      for(auto &adj: graph[node]){
        temp += dfs(adj, 2, graph, apple, vis);
      }
      if(temp == 0 and !apple[node]) return 0;
      return (time + temp);
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& apple) {
      vector<vector<int>> graph(n);
      vector<bool> vis(n, false);
      for(auto &e: edges){
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
      }
      return dfs(0, 0, graph, apple, vis);
    }
};