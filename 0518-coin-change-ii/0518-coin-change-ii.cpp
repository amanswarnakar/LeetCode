class Solution {
public:
    int f(int idx, int t, vector<int> &v, vector<vector<int>> &dp){
      if(idx == 0) return (t % v[0] == 0);
      if(dp[idx][t] != -1) return dp[idx][t];
      int pick = 0;
      if(v[idx] <= t) pick = f(idx, t - v[idx], v, dp);
      int notPick = f(idx - 1, t, v, dp);
      return dp[idx][t] = pick + notPick;
    }
    int change(int tar, vector<int>& v) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
      return f(n - 1, tar, v, dp);
    }
};