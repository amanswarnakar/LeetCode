class Solution {
public:
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
};