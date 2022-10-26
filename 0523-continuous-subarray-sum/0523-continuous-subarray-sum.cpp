class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      // vector<int> v(k, -1);     // Vector bad because of memory allocation
      // for test case - [1000000000] 1000000000
      unordered_map<int, int> um;
      int preSum = 0;
      for(int i = 0; i < n; i++){
        preSum += nums[i];
        preSum %= k;
        if(preSum == 0 and i) return true;
        if(um.find(preSum) != um.end()){
          if(i - um[preSum] > 1) return true;
        } else um[preSum] = i;
      }
      return false;      
      
      // WRONG APPROACH
      
      // int n = nums.size();
      // cout<<accumulate(nums.begin(), nums.end(), 0);
      // if(n == 1) return false;
      // if(accumulate(nums.begin(), nums.end(), 0ll) == 0) return true;
      // if(accumulate(nums.begin(), nums.end(), 0ll) < k) return false;
      // vector<int> sumArr(n + 1);
      // for(int i = 0; i < n; i++){
      //   sumArr[i + 1] = sumArr[i] + nums[i];
      // }
      // int l = 0, r = 2;
      // // for(auto i : sumArr) cout<<i<<" ";
      // // cout<<endl;
      // while(l < n){
      //   for(int i = l + 2; i < n + 1; i++){
      //     // cout<<sumArr[i] - sumArr[l]<<endl;
      //     if((sumArr[i] - sumArr[l]) % k == 0) return true;
      //   }
      //   l++;
      // }
      // return false;
    }
};