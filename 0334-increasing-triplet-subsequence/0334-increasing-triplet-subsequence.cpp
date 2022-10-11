class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      // Brute Force - TC - o(n^3) TLE
      // int n = nums.size();
      // for(int i = 0; i < n - 2; i++){
      //   for(int j = i + 1; j < n - 1; j++){
      //     for(int k = j + 1; k < n; k++){
      //       if(nums[i] < nums[j] and nums[j] < nums[k]) return true;
      //     }
      //   }
      // }
      // return false;
      
      // int l = 0, r = nums.size() - 1, n = nums.size();
      // while(l < r){
      //   if(nums[l] < nums[r]){
      //     for(int i = l + 1; i < r; i++){
      //       if(nums[l] < nums[i] and nums[i] < nums[r]) return true;
      //     }
      //   } else {
      //     if(nums[l] < nums[r-1]) r--;
      //     else if(nums[l+1] < nums[r]) l++;
      //     else {
      //       l++; r--;
      //     }
      //   }
      // }
      // return false;
      
      int n = nums.size(), p = INT_MAX, q = INT_MAX;
      for(int i = 0; i < n; i++){
        if(nums[i] <= p) p = nums[i];
        else if(nums[i] <= q) q = nums[i];
        else return true;
      }
      return false;
    }
};