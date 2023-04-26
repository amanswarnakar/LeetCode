class Solution {
public:
    int solve(int c1, int c2, int r, vector<vector<int>> &g, vector<vector<vector<int>>> &dp){
      if(min(c1, c2) < 0 or max(c1, c2) == g[0].size()) return 0;
      if(r == g.size() - 1)
        return c1 == c2 ? g[r][c1] : g[r][c1] + g[r][c2];
      if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
      int temp = 0;
      for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
          temp = max(temp, solve(c1 + i, c2 + j, r + 1, g, dp));
        }
      }
      int res = c1 == c2 ? g[r][c1] + temp : g[r][c1] + g[r][c2] + temp;
      return dp[r][c1][c2] = res;
    }
    int cherryPickup(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
      int ans = solve(0, n - 1, 0, g, dp);
      return ans;
    }
};