class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      set<vector<int>> sv;
      for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
          for(int k = j+1; k < n; k++){
            long long x = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
            if(binary_search(nums.begin() + k + 1, nums.end(), x)){
              vector<int> vec;
              vec.push_back(nums[i]);
              vec.push_back(nums[j]);
              vec.push_back(nums[k]);
              vec.push_back(x);
              sv.insert(vec);
            }
          }
        }
      }
      vector<vector<int>> ans(sv.begin(), sv.end());
      return ans;
    }
};