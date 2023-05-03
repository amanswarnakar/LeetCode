class Solution {
public:
    int f(int idx, int t, vector<int> &v, vector<vector<int>> &dp){
      if(idx == 0){
        if(t % v[idx] == 0) return (t / v[idx]);
        else return 1e9;
      }
      if(dp[idx][t] != -1) return dp[idx][t];
      int pick = 1e9;
      if(v[idx] <= t) pick = 1 + f(idx, t - v[idx], v, dp);
      int notPick = f(idx - 1, t, v, dp);
      return dp[idx][t] = min(pick, notPick);
    }
    int coinChange(vector<int>& v, int t) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(t + 1, -1));
      int ans = f(n - 1, t, v, dp);
      return ans >= 1e9? -1 : ans;
    }
};