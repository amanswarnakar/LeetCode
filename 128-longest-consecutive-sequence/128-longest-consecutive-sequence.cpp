class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n = nums.size();
      if(nums.empty()){
        return 0;
      }
      sort(nums.begin(), nums.end());
      int ans = 0, temp = 0;
      for(int i = 0; i < n-1; i++){
        if(nums[i+1] - nums[i] == 1){
          temp++;
        } else if(nums[i+1] == nums[i]){
          continue;
        } else {
          temp = 0;
        }
        ans = max(temp, ans);
      }
      return ans+1;
    }
};