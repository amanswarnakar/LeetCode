class Solution {
public:
    int coinChange(vector<int>& v, int t) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(t + 1, 0));
      for(int i = 0; i < t + 1; i++){
        if(i % v[0] == 0) dp[0][i] = i / v[0];
        else dp[0][i] = 1e9;
      }
      for(int i = 1; i < n; i++){
        for(int j = 0; j < t + 1; j++){
          int notPick = 0 + dp[i - 1][j];
          int pick = INT_MAX;
          if(v[i] <= j){
            pick = 1 + dp[i][j - v[i]];
          }
          dp[i][j] = min(pick, notPick);
        }
      }
      // for(auto i: dp){
      //   for(auto j: i) cout<<j<<" ";
      //   cout<<endl;
      // }
      int ans = dp[n - 1][t];
      return ans >= 1e9 ? -1 : ans;
    }
  
  /*
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
  */
};