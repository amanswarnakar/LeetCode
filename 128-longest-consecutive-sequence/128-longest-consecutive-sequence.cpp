class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // Approach 1 - Sorting
        // TC- O(nlogn + n)     SC- O(1)
      
      // int n = nums.size();
      // if(nums.empty()){
      //   return 0;
      // }
      // sort(nums.begin(), nums.end());
      // int ans = 0, temp = 0;
      // for(int i = 0; i < n-1; i++){
      //   if(nums[i+1] - nums[i] == 1){
      //     temp++;
      //   } else if(nums[i+1] == nums[i]){
      //     continue;
      //   } else {
      //     temp = 0;
      //   }
      //   ans = max(temp, ans);
      // }
      // return ans+1;
      
        // Approach 2 - HashSet
        // TC- O(n)     SC- O(n)
      
      int n = nums.size();
      set<int> hashSet;
      for(auto num : nums){
        hashSet.insert(num);
      }
      
      int ans = 0;
      
      for(auto num : hashSet){
        if(!hashSet.count(num-1)){
          int cnt = 1;
          int num2 = num;
          while(hashSet.count(num2+1)){
            cnt++;
            num2++;
          }
          ans = max(ans, cnt);
        }
      }
      return ans;      
    }
};