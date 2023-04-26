class Solution {
public:
    int solve(int r, int c, vector<vector<int>> &g, vector<vector<int>> &dp){
      if(r < 0 or c < 0 or g[r][c] == 1) return 0;
      if(r == 0 and c == 0) return 1;
      if(dp[r][c] != -1) return dp[r][c];
      int top = solve(r - 1, c, g, dp);
      int left = solve(r, c - 1, g, dp);
      // if(top < 0) return dp[r][c] = left < 0 ? 0 : left;
      // if(left < 0) return dp[r][c] = top < 0 ? 0 : top;
      return dp[r][c] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector dp(m, vector<int>(n, -1));
      return solve(m - 1, n - 1, g, dp);
    }
};