class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int currNode){
      vis[currNode] = true;
      int n = graph.size();
      // for(auto &node: graph[currNode]){
      //   if(!vis[node])
      //     dfs(graph, vis, node);
      // }
      for(int i = 0; i < n; i++){
        if(graph[currNode][i] and !vis[i])
          dfs(graph, vis, i);
      }
    }
    int findCircleNum(vector<vector<int>>& con) {
      int n = con.size();
      int ans = 0;
      vector<bool> vis(n, false);
      // vector<vector<int>> graph(n);
      // for(int i = 0; i < n; i++){
      //   for(int j = i; j < n; j++){
      //     if(con[i][j]){
      //       graph[i].emplace_back(j);
      //       graph[j].emplace_back(i);
      //     }
      //   }
      // }
      for(int i = 0; i < n; i++){
        if(!vis[i]){
          dfs(con, vis, i);
          // dfs(graph, vis, i); 
          ans++;
        }
      }
      return ans;
    }
};