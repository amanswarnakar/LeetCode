class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size(), ans = INT_MAX;
      vector<vector<int>> dp(m, vector<int>(n + 2, INT_MAX));
      for(int i = 1; i < n + 1; i++){
        dp[m - 1][i] = v[m - 1][i - 1];
      }
      for(int i = m - 2; i >= 0; i--){
        for(int j = 1; j < n + 1; j++){
          dp[i][j] = v[i][j - 1] + min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
        }
      }
      for(auto i: dp[0])
        ans = min(ans, i);
      return ans;
    }
};