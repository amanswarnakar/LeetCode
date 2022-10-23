class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size(), x, y;
      vector<int> v(n + 1, 0);
      for(int i = 0; i < n; i++){
        v[nums[i]]++;
      }
      for(int i = 1; i < n + 1; i++){
        if(v[i] == 2) x = i;
        else if(v[i] == 0) y = i;
      }
      return {x, y};
    }
};