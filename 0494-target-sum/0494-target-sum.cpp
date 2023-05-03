class Solution {
public:
    int findTargetSumWays(vector<int>& v, int tar) {
      int n = v.size(), sum = accumulate(v.begin(), v.end(), 0);
      if((sum - tar) % 2 or (sum - tar) < 0) return 0;
      int t = (sum - tar) / 2;
      vector<vector<int>> dp(n, vector<int>(t + 1, 0));
      for(int i = 0; i < t + 1; i++){
        if(v[0] == 0 and i == 0) dp[0][0] = 2;
        else if(v[0] == i or i == 0) dp[0][i] = 1;
      }
      for(int i = 1; i < n; i++){
        for(int j = 0; j < t + 1; j++){
          int pick = 0;
          if(v[i] <= j) pick = dp[i - 1][j - v[i]];
          int notPick = dp[i - 1][j];
          dp[i][j] = pick + notPick;
        }
      }
      return dp[n - 1][t];
    }
  
    /*
    int f(int idx, int t, vector<int> &v, vector<vector<int>> &dp){
      if(idx == 0){
        if(v[0] == 0 and t == 0) return 2;
        else if(v[0] == t or t == 0) return 1;
        return 0;
      }
      if(dp[idx][t] != -1) return dp[idx][t];
      int pick = 0;
      if(v[idx] <= t) pick = f(idx - 1, t - v[idx], v, dp);
      int notPick = f(idx - 1, t, v, dp);
      return dp[idx][t] = pick + notPick;
    }
      
    int findTargetSumWays(vector<int>& v, int tar) {
      int n = v.size(), sum = accumulate(v.begin(), v.end(), 0);
      if((sum - tar) % 2 or (sum - tar) < 0) return 0;
      int t = (sum - tar) / 2;
      vector<vector<int>> dp(n, vector<int>(t + 1, -1));
      return f(n - 1, t, v, dp);
    }
    */
};