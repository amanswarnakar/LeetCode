class Solution {
public:
    inline vector<int> sortedSquares(vector<int>& nums) {
      for(auto &num : nums)
        num *= num;
      sort(nums.begin(), nums.end());
      return nums;
    }
};