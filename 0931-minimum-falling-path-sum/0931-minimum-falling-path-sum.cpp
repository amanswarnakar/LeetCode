class Solution {
public:
    int solve(int r, int c, vector<vector<int>> &g, vector<vector<int>> &dp){
      if(c < 0 or c == g[0].size()) return 1e9;
      if(r == 0) return g[0][c];
      if(dp[r][c] != -1) return dp[r][c];
      int top = solve(r - 1, c, g, dp);
      int topLeft = solve(r - 1, c - 1, g, dp);
      int topRight = solve(r - 1, c + 1, g, dp);
      return dp[r][c] = g[r][c] + min(top, min(topLeft, topRight));
    }
  
    int minFallingPathSum(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      int ans = INT_MAX;
      vector<vector<int>> dp(m, vector<int>(n, -1));
      for(int i = 0; i < n; i++){
        ans = min(ans, solve(m - 1, i, g, dp));
      }
      return ans;
    }
};