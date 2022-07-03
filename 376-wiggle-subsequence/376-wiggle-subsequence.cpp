class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      if(n <= 2){
        return 1;
      }
      vector<int> v(n-1);
      for(int i = 0; i < n-1; i++){
        v[i] = nums[i+1] - nums[i];
      }
      int up = 0, down = 0;
      for(int i = 0; i < n-1; i++){
        if(v[i] > 0){
          up = down + 1;
        } else if(v[i] < 0) {
          down = up + 1;
        }
      }
      return 1 + max(up, down);
    }
};