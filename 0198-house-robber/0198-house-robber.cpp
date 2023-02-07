class Solution {
public:
//     int helper(vector<int> &nums, vector<int> &dp, int idx){
//       if(idx == 0) return nums[0];
//       if(idx < 0) return 0;
      
//       if(dp[idx] != -1) return dp[idx];
      
//       int pick = nums[idx] + helper(nums, dp, idx - 2);
//       int notPick = 0 + helper(nums, dp, idx - 1);
      
//       return dp[idx] = max(pick, notPick);
//     }
    int rob(vector<int>& nums) {
      // Memoization
      
      // int n = nums.size();
      // vector<int> dp(n, -1);
      // return helper(nums, dp, n - 1);
      
      // Tabulation
      
      int n = nums.size();
      vector<int> dp(n, nums[0]);
      for(int i = 1; i < n; i++){
        dp[i] = nums[i];
        if(i > 1) dp[i] += dp[i - 2];
        dp[i] = max(dp[i], dp[i - 1]);
      }
      return dp[n - 1];
    }
};