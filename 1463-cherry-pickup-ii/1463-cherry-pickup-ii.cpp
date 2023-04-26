class Solution {
public:
    vector<int> dx = {-1, 0, 1};
    int solve(int c1, int c2, int r, vector<vector<int>> &g, vector<vector<vector<int>>> &dp){
      if(min(c1, c2) < 0 or max(c1, c2) == g[0].size()) return 0;
      if(r == g.size() - 1){
        if(c1 == c2) return g[r][c1];
        return g[r][c1] + g[r][c2];
      } 
      if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
      int temp = 0;
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          temp = max(temp, solve(c1 + dx[i], c2 + dx[j], r + 1, g, dp));
        }
      }
      if(c1 != c2)
        return dp[r][c1][c2] = g[r][c1] + g[r][c2] + temp;
      return  dp[r][c1][c2] = g[r][c1] + temp;
    }
    int cherryPickup(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
      int ans = solve(0, n - 1, 0, g, dp);
      return ans;
    }
};