class Solution {
public:
    int solve(int r1, int c1, int r2, vector<vector<int>> &g, vector<vector<vector<int>>> &dp){
      int c2 = r1 + c1 - r2;
      if(min(r1, r2) < 0 or min(c1, c2) < 0 or g[r1][c1] == -1 or g[r2][c2] == -1) 
        return -1e8;
      if(r1 == 0 and c1 == 0) return g[r1][c1];
      if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
      int res = g[r1][c1], temp = 0;
      if(r1 != r2) res += g[r2][c2];
      
      temp = max(solve(r1 - 1, c1, r2 - 1, g, dp), solve(r1, c1 - 1, r2, g, dp));
      temp = max(temp, solve(r1 - 1, c1, r2, g, dp));
      temp = max(temp, solve(r1, c1 - 1, r2 -1, g, dp));
      
      res += temp;
      return dp[r1][c1][r2] = res;
    }
  
    int cherryPickup(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size(), ans = 0;
      vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m, -1)));
      ans = solve(m - 1, n - 1, m - 1, g, dp);
      return max(ans, 0);
    }
};