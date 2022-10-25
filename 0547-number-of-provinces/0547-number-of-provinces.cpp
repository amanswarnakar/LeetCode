class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int currNode){
      vis[currNode] = true;
      for(int i = 0; i < graph.size(); i++){
        if(graph[currNode][i] == 1 and !vis[i])
          dfs(graph, vis, i);
      }
    }
  
    int findCircleNum(vector<vector<int>>& v) {
      int ans = 0, n = v.size();
      vector<bool> vis(n, false);
      for(int i = 0; i < n; i++){
        if(!vis[i]){
          ans++; dfs(v, vis, i);
        }
      }
      return ans;
    }
  
  
    // Wrong Approach
  
//     int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  
//     void dfs(vector<vector<int>> &v, vector<vector<int>> &vis, int r, int c){
//       if(min(r, c) < 0 or r >= v.size() or c >= v[0].size() or vis[r][c] == 1 or v[r][c] == 0) return;
//       vis[r][c] = 1;
//       for(int i = 0; i < 4; i++)
//         dfs(v, vis, r + dx[i], c + dy[i]);
//     }
  
//     int findCircleNum(vector<vector<int>>& v) {
//       int m = v.size(), n = v[0].size(), ans = 0;
//       vector<vector<int>> vis(m, vector<int>(n, 0));
//       for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//           if(v[i][j] == 1 and vis[i][j] == 0)
//             dfs(v, vis, i, j), ans++;
//         }
//       }
//       return ans;
//     }
};