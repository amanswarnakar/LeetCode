class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      // HashMap Solution - TLE
      
      // int n = nums.size();
      // // sort(nums.begin(), nums.end());
      // set<vector<int>> ans;
      // map<int, int> mp;
      // for(int i = 0; i < n; i++){
      //   mp[nums[i]]++;
      // }
      // for(int i = 0; i < n; i++){
      //   mp[nums[i]]--;
      //   for(int j = i+1; j < n; j++){
      //     mp[nums[j]]--;
      //     if(mp.find(-1*(nums[i] + nums[j])) != mp.end() and mp[-1*(nums[i] + nums[j])] > 0){
      //       vector<int> temp;
      //       temp = {nums[i], nums[j], -1 * (nums[i] + nums[j])};
      //       // temp.push_back(nums[i]);
      //       // temp.push_back(nums[j]);
      //       // temp.push_back(-1 * (nums[i] + nums[j]));
      //       sort(temp.begin(), temp.end());
      //       ans.insert(temp);
      //     }
      //     mp[nums[j]]++;
      //   }
      //   mp[nums[i]]++;
      // }
      // return vector<vector<int>>(ans.begin(), ans.end());
      
      // Two Pointer Approach
      
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;
      for(int i = 0; i < n-2; i++){
        if(i == 0 or (i > 0 and nums[i] != nums[i-1])){
          int l = i+1, r = n-1, t = 0 - nums[i];
          while(l < r){
            if(nums[l] + nums[r] == t){
              ans.push_back({nums[i], nums[l], nums[r]});
              while(l < r and nums[l] == nums[l+1]) l++;
              while(l < r and nums[r] == nums[r-1]) r--;
              l++; r--;
            }
            else if(nums[l] + nums[r] < t) l++;
            else r--;
          }
        }
      }
      return ans;
    }
};