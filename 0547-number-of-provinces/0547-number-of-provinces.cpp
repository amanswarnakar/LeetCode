class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int currNode){
      vis[currNode] = true;
      for(auto &node: graph[currNode]){
        if(!vis[node])
          dfs(graph, vis, node);
      }
    }
    int findCircleNum(vector<vector<int>>& con) {
      int n = con.size();
      vector<vector<int>> graph(n);
      vector<bool> vis(n, false);
      for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
          if(con[i][j]){
            graph[i].emplace_back(j);
            graph[j].emplace_back(i);
          }
        }
      }
      int ans = 0;
      for(int i = 0; i < n; i++){
        if(!vis[i]){
          dfs(graph, vis, i); 
          ans++;
        }
      }
      return ans;
    }
};