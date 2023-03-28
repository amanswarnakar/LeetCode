class Solution {
public:
    int recur(int idx, vector<int> &v, int n, vector<int> &dp){
      if(idx == 0) return v[0];
      if(idx < 0) return 0;
      if(dp[idx] != -1) return dp[idx];
      int pick = v[idx] + recur(idx - 2, v, n, dp);
      int notPick = 0 + recur(idx - 1, v, n, dp);
      return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& v) {
      int n = v.size();
      if(n <= 2) return *max_element(v.begin(), v.end());
      vector<int> v1, v2, dp(n - 1, -1);
      for(int i = 0; i < n; i++){
        if(i != 0) v1.emplace_back(v[i]);
        if(i != n - 1) v2.emplace_back(v[i]);
      }
      int x = recur(n - 2, v1, n - 1, dp);
      for(auto &i: dp) i = -1;
      int y = recur(n - 2, v2, n - 1, dp);
      return max(x, y);
    }
};