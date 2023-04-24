class Solution {
public:
    int solve(int idx, vector<int> &v, vector<int> &dp){
      if(idx < 0) return 0;
      if(dp[idx] != -1) return dp[idx];
      int pick = v[idx] + solve(idx - 2, v, dp);
      int notPick = solve(idx - 1, v, dp);
      return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& v) {
      int n = v.size(), ans = 0;
      if(n <= 2) return *max_element(v.begin(), v.end());
      vector<int> v1, v2, dp(n - 1, -1);
      for(int i = 0; i < n; i++){
        if(i != n - 1) v1.emplace_back(v[i]);
        if(i != 0) v2.emplace_back(v[i]);
      }
      ans = solve(n - 2, v1, dp);
      for(auto &i: dp) i = -1;
      ans = max(ans, solve(n - 2, v2, dp));
      return ans;
    }
};