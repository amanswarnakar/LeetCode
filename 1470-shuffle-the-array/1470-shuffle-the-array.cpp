class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
      vector<int> ans;
      int j = n;
      for(int i = 0; i < n; i++, j++){
        ans.emplace_back(nums[i]);
        ans.emplace_back(nums[j]);
      }
      return ans;
    }
};