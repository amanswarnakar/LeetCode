class Solution {
public:
    static bool comp(int a, int b){
      return abs(a) < abs(b);
    }
    vector<int> sortedSquares(vector<int>& nums) {
      sort(nums.begin(), nums.end(), comp);
      for(int i = 0; i < nums.size(); i++){
        nums[i] *= nums[i];
      }
      return nums;
    }
};