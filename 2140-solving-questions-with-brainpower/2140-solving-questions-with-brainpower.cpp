class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
      int n = v.size();
      vector<long long> dp(n, 0);
      dp[n - 1] = v[n - 1][0];
      for(int idx = n - 2; idx >= 0; idx--){
        long long pick = v[idx][0];
        if(idx + 1 + v[idx][1] < n)
          pick += dp[idx + v[idx][1] + 1];
        long long notPick = dp[idx + 1];
        dp[idx] = max(pick, notPick);
      }
      return dp[0];
    }
  /*
    long long f(int idx, vector<vector<int>> &v, vector<long long> &dp){
      if(idx >= v.size()) return 0;
      if(dp[idx] != -1) return dp[idx];
      long long pick = v[idx][0] + f(idx + v[idx][1] + 1, v, dp);
      long long notPick = f(idx + 1, v, dp);
      return dp[idx] = max(pick, notPick);
    }
    long long mostPoints(vector<vector<int>>& v) {
      int n = v.size();
      vector<long long> dp(n, -1);
      return f(0, v, dp);
    }
  */
};