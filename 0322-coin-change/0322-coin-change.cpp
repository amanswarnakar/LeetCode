class Solution {
public:
    int recur(int idx, int t, vector<int> &v, vector<vector<int>> &dp){
      if(dp[idx][t] != -1) return dp[idx][t];
      if(idx == 0){
        if(t % v[idx] == 0) return t / v[idx];
        return 1e9;
      }
      int pick = INT_MAX;
      int notPick = 0 + recur(idx - 1, t, v, dp);
      if(v[idx] <= t){
        pick = 1 + recur(idx, t - v[idx], v, dp);
      }
      return dp[idx][t] = min(pick, notPick);
    }
    int coinChange(vector<int>& v, int t) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(t + 1, -1));
      int ans = recur(n - 1, t, v, dp);
      return ans >= 1e9 ? -1 : ans;
    }
};