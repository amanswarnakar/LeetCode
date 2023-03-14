class Solution {
public:
    int f(int l, int r, vector<int> &v, vector<vector<int>> &dp){
      if(l > r) return 0;
      if(dp[l][r] != -1) return dp[l][r];
      int maxi = INT_MIN;
      for(int i = l; i <= r; i++){
        int temp = v[l - 1] * v[i] * v[r + 1] + f(l, i - 1, v, dp) + f(i + 1, r, v, dp);
        maxi = max(temp, maxi);
      }
      return dp[l][r] = maxi;
    }
    int maxCoins(vector<int>& v) {
      int n = v.size();
      v.emplace_back(1);
      vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
      v.insert(v.begin(), 1);
      return f(1, n, v, dp);
    }
};