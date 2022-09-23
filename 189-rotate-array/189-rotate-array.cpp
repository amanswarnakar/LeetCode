class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size(), idx = 0;
      k %= n;
      if(n == 1) return;
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k);
      reverse(nums.begin() + k, nums.end());
      
      // 1 2 3 4 5      k = 1
      // 5 1 2 3 4
      // 0 1 2 3 4
    }
};