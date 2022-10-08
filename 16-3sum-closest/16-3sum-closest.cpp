class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
      sort(nums.begin(), nums.end());
      int n = nums.size(), ans = 0, mini = INT_MAX;
      if(n == 3) return accumulate(nums.begin(), nums.end(), 0);
      for(int i = 0; i < n - 2; i++){
        int temp = nums[i];
        int l = i + 1, r = n - 1;
        while(l < r){
          int sum = temp + nums[l] + nums[r];
          if(abs(sum - t) < mini){
            mini = abs(sum - t);
            ans = sum;
          }
          if(sum < t) l++;
          else if(sum > t) r--;
          else return t;
        }
      }
      return ans;
    }
};