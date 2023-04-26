class Solution {
public:
    int solve(int r, int idx, vector<vector<int>> &v, vector<vector<int>> &dp){
      if(r == 0) return v[0][0];
      if(idx < 0 or idx == v[r].size()) return 1e9;
      if(dp[r][idx] != -1) return dp[r][idx];
      int topLeft = 1e9, topRight = 1e9;
      topLeft = solve(r - 1, idx - 1, v, dp);
      topRight = solve(r - 1, idx, v, dp);
      return dp[r][idx] = v[r][idx] + min(topLeft, topRight);
    }
  
    int minimumTotal(vector<vector<int>>& v) {
      int n = v.size();
      int ans = INT_MAX;
      vector dp(n, vector<int>(n, -1));
      for(int i = 0; i < n; i++){
        int temp = solve(n - 1, i, v, dp);
        ans = min(ans, temp);
      }
      return ans;
    }
};