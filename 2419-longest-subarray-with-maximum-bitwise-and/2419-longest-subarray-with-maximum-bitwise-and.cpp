class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      // Finding the consecutive maximum element bc that will give us the max bitwise and of the given array
      int ans = 0, temp = 0;
      int maxi = *max_element(nums.begin(), nums.end());
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] == maxi) temp++;
        else temp = 0;
        ans = max(temp, ans);
      }
      return ans;
    }
};