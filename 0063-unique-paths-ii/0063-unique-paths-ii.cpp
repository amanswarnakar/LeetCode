class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector dp(m, vector<int>(n, 0));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(g[i][j] == 1) dp[i][j] = 0;
          else if(i == 0 and j == 0) dp[i][j] = 1;
          else {
            int top = 0, left = 0;
            if(i > 0) top = dp[i - 1][j];
            if(j > 0) left = dp[i][j - 1];
            dp[i][j] = top + left;
          }
        }
      }
      return dp[m - 1][n - 1];
    }
  
  /*
    int solve(int r, int c, vector<vector<int>> &g, vector<vector<int>> &dp){
      if(r < 0 or c < 0 or g[r][c] == 1) return 0;
      if(r == 0 and c == 0) return 1;
      if(dp[r][c] != -1) return dp[r][c];
      int top = solve(r - 1, c, g, dp);
      int left = solve(r, c - 1, g, dp);
      return dp[r][c] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector dp(m, vector<int>(n, -1));
      return solve(m - 1, n - 1, g, dp);
    }  
  */
};