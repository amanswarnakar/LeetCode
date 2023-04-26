class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector<int> prev(n, 1e9);
      for(int i = 0; i < m; i++){
        vector<int> curr(n, 1e9);
        for(int j = 0; j < n; j++){
          if(i == 0 and j == 0) curr[j] = g[i][j];
          else {
            int top = 1e9, left = 1e9;
            if(i > 0) top = prev[j];
            if(j > 0) left = curr[j - 1];
            curr[j] = g[i][j] + min(top, left);
          }
        }
        prev = curr;
      }
      return prev[n - 1];
    }
  
  /*
  // Tabulation
  
    int minPathSum(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector dp(m, vector<int>(n, 1e9));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(i == 0 and j == 0) dp[i][j] = g[i][j];
          else {
            int top = 1e9, left = 1e9;
            if(i > 0) top = dp[i - 1][j];
            if(j > 0) left = dp[i][j - 1];
            dp[i][j] = g[i][j] + min(top, left);
          }
        }
      }
      return dp[m - 1][n - 1];
    }
  
  // Memoization
  
    int solve(int r, int c, vector<vector<int>> &g, vector<vector<int>> &dp){
      if(r < 0 or c < 0) return 1e9;
      if(r == 0 and c == 0) return g[0][0];
      if(dp[r][c] != -1) return dp[r][c];
      int top = solve(r - 1, c, g, dp);
      int left = solve(r, c - 1, g, dp);
      return dp[r][c] = g[r][c] + min(top, left);
    }
  
    int minPathSum(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector dp(m, vector<int>(n, -1));
      return solve(m - 1, n - 1, g, dp);
    }
  */
};