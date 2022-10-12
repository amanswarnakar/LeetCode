class Solution {
public:
    void dfs(vector<vector<int>> &v, int r, int c){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size() or v[r][c] == 0) return;
      v[r][c] = 0;
      dfs(v, r+1, c);
      dfs(v, r-1, c);
      dfs(v, r, c+1);
      dfs(v, r, c-1);
    }
    
    int numEnclaves(vector<vector<int>>& g) {
      int ans = 0, m = g.size(), n = g[0].size();
      if(m <= 2 or n <= 2) return 0;
      for(int i = 0; i < m; i++){
        if(g[i][0] == 1) dfs(g, i, 0);
        if(g[i][n-1] == 1) dfs(g, i, n-1);
      }
      for(int i = 0; i < n; i++){
        if(g[0][i] == 1) dfs(g, 0, i);
        if(g[m-1][i] == 1) dfs(g, m-1, i);
      }
      for(int i = 1; i < m-1; i++){
        for(int j = 1; j < n-1; j++){
          if(g[i][j] == 1) ans++;
        }
      }
      return ans;
    }
};