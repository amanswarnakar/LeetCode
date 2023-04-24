class Solution {
public:
    int solve(vector<int> &v){
      // Space Optimisation
      
      int n = v.size();
      // vector<int> dp(n, -1);
      int p1 = v[0], p2 = 0, curr = 0;
      for(int i = 1; i < n; i++){
        int pick = v[i];
        if(i > 1) pick += p2;
        int notPick = p1;
        p2 = p1;
        curr = max(pick, notPick);
        p1 = curr;
      }
      return p1;
      
      
      // Tabulation
      
      // int n = v.size();
      // vector<int> dp(n, -1);
      // dp[0] = v[0];
      // for(int i = 1; i < n; i++){
      //   int pick = v[i];
      //   if(i > 1) pick += dp[i - 2];
      //   int notPick = dp[i - 1];
      //   dp[i] = max(pick, notPick);
      // }
      // return dp[n - 1];
    }
  
    int rob(vector<int>& v) {
      int n = v.size(), ans = 0;
      if(n <= 2) return *max_element(v.begin(), v.end());
      vector<int> v1, v2;
      // vector<int> dp(n - 1, -1);
      for(int i = 0; i < n; i++){
        if(i != n - 1) v1.emplace_back(v[i]);
        if(i != 0) v2.emplace_back(v[i]);
      }
      ans = max(solve(v1), solve(v2));
      return ans;
    }
  /*
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
  */
};