class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size();
      vector<int> presum(n, nums[0]), postsum(n, nums[n-1]);
      for(int i = 1; i < n; i++){
        presum[i] = presum[i-1] + nums[i];
      }
      for(int i = n - 2; i >= 0; i--){
        postsum[i] = postsum[i+1] + nums[i];
      }
      for(int i = 0; i < n; i++){
        if(presum[i] == postsum[i]) return i;
      }
      //  1  8 11 17 22 28
      // 28 27 20 17 11  6
      return -1;
    }
};