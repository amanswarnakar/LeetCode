class Solution {
public: 
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
};