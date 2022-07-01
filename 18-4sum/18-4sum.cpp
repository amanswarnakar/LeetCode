class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Optimized Solution
      int n = nums.size();
      vector<vector<int>> ans;
      if(nums.empty()){
        return ans;
      }
      sort(nums.begin(), nums.end());
      for(int i = 0; i < n; i++){
        long long target2 = target - nums[i];
        for(int j = i+1; j < n; j++){
          int l = j+1, r = n-1;
          long long target3 = target2 - nums[j];
          while(l < r){
            long long sum2 = (long long)nums[l] + (long long)nums[r];
            if(sum2 < target3) l++;
            else if(sum2 > target3) r--;
            else {
              vector<int> v(4, 0);
              v[0] = nums[i];
              v[1] = nums[j];
              v[2] = nums[l];
              v[3] = nums[r];
              ans.push_back(v);
              
              // Skipping duplicate values
              while(l < r and nums[l] == v[2]) l++;
              while(l < r and nums[r] == v[3]) r--;
            }
            while(j + 1 < n and nums[j+1] == nums[j]) j++;
          }
          while(i + 1 < n and nums[i+1] == nums[i]) i++;
        }
      }
      return ans;
      
      
      
      
        // Brute Force
      /*
      Time complexity - o(n^3.logn + nlogn)   
      n^3.logn for 3 loops and binary search
      nlogn for sorting 
      */
      
      // int n = nums.size();
      // sort(nums.begin(), nums.end());
      // set<vector<int>> sv;
      // for(int i = 0; i < n; i++){
      //   for(int j = i+1; j < n; j++){
      //     for(int k = j+1; k < n; k++){
      //       long long x = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
      //       if(binary_search(nums.begin() + k + 1, nums.end(), x)){
      //         vector<int> vec;
      //         vec.push_back(nums[i]);
      //         vec.push_back(nums[j]);
      //         vec.push_back(nums[k]);
      //         vec.push_back(x);
      //         sv.insert(vec);
      //       }
      //     }
      //   }
      // }
      // vector<vector<int>> ans(sv.begin(), sv.end());
      // return ans;
    }
};