class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      // int n = nums.size(), idx = 0;
      // k %= n;
      // if(n == 1) return;
      // reverse(nums.begin(), nums.end());
      // reverse(nums.begin(), nums.begin() + k);
      // reverse(nums.begin() + k, nums.end());

      int n = nums.size();
      k = k % n;
      k = n - k;
      int temp = k, i = 0;
      vector<int> ans(n);
      while(temp < n){
        ans[i++] = nums[temp++];
      }
      temp = 0;
      while(temp < k){
        ans[i++] = nums[temp++];
      }
      for(int i = 0; i < n; i++)
        nums[i] = ans[i];
    }
};