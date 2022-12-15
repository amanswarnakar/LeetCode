class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size();
      vector<int> psum(n + 1, 0);
      for(int i = 0; i < n; i++){
        psum[i + 1] = nums[i] + psum[i];
      }
      for(int i = 0; i < n; i++){
        if(psum[i + 1] - nums[i] == psum[n] - psum[i + 1]) return i;
      }
      return -1;
    }
};