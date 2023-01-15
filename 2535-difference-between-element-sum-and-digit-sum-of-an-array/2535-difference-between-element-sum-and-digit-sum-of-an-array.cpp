class Solution {
public:
    int helper(int num){
      int res = 0;
      while(num){
        res += num % 10;
        num /= 10;
      }
      return res;
    }
    int differenceOfSum(vector<int>& nums) {
      int dig = 0;
      for(auto &i: nums){
        dig += helper(i);
      }
      return abs(dig - accumulate(nums.begin(), nums.end(), 0));
    }
};