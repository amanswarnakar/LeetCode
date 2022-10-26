class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size(), dis = 0;
      for(int i = 0; i <= dis; i++){
        dis = max(dis, i + nums[i]);
        if(dis >= n - 1) return true;
      }
      return false;
    }
};