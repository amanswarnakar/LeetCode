class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Brute Force
      
      // for(int i = 0; i < nums.size()-1; i++){
      //   for(int j = i+1; j < nums.size(); j++){
      //     if(nums[i] + nums[j] == target){
      //       return {i, j};
      //     }
      //   }
      // }
      // return {};
      
        // Hash Map
      
      map<int, int> mp;
      for(int i = 0; i < nums.size(); i++){
        mp[nums[i]] = i;    // Storing indices of each elements
      }
      int n = nums.size();
      for(int i = 0; i < n; i++){
        if(mp.find(target - nums[i]) != mp.end()){    // Checking if the target - nums[i] exists or not
          if(mp[target - nums[i]] != i){   // To avoid addition of same element twice
            return {i, mp[target - nums[i]]};
          }
        }
      }
      return {0, 0};
    }
};