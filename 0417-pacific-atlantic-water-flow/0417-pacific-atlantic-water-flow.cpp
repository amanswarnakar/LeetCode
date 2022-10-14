class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>> &v, vector<vector<int>> &vis, int r, int c, int ph){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size()) return;
      if(vis[r][c] == 1 or v[r][c] < ph) return;
      vis[r][c] = 1;
      for(int i = 0; i < 4; i++)
        dfs(v, vis, r + dx[i], c + dy[i], v[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size();
      vector<vector<int>> ans, pac(m, vector<int>(n, 0)), atl(m, vector<int>(n, 0));
      for(int i = 0; i < n; i++){
        dfs(v, pac, 0, i, v[0][i]);
        dfs(v, atl, m - 1, i, v[m - 1][i]);
      }
      for(int i = 0; i < m; i++){
        dfs(v, pac, i, 0, v[i][0]);
        dfs(v, atl, i, n - 1, v[i][n - 1]);
      }
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(atl[i][j] == 1 and pac[i][j] == 1)
            ans.push_back({i, j});
        }
      }
      return ans;
    }
};