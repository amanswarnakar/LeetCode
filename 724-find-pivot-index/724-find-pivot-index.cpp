class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      // Prefix Sum Approach;  TC = O(3N) SC = O(2N)
      
      // int n = nums.size();
      // vector<int> presum(n, nums[0]), postsum(n, nums[n-1]);
      // for(int i = 1; i < n; i++){
      //   presum[i] = presum[i-1] + nums[i];
      // }
      // for(int i = n - 2; i >= 0; i--){
      //   postsum[i] = postsum[i+1] + nums[i];
      // }
      // for(int i = 0; i < n; i++){
      //   if(presum[i] == postsum[i]) return i;
      // }
      // //  1  8 11 17 22 28
      // // 28 27 20 17 11  6
      // return -1;
      
      // TC = O(2N) SC = O(1)
      
      int n = nums.size(), sum = 0, lsum = 0;
      for(int i = 0; i < n; i++) sum += nums[i];
      
      for(int i = 0; i < n; i++){
        if(lsum == sum - lsum - nums[i]) return i;
        lsum += nums[i];
      }
      return -1;
    }
};