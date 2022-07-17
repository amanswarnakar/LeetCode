class Solution {
public:
    void sortColors(vector<int>& nums) {
      // map<int, int> mp;
      // for(int i = 0; i < nums.size(); i++){
      //   mp[nums[i]]++;
      // }
      // int idx = 0;
      // for(auto i: mp){
      //   while(i.second > 0) {
      //     nums[idx++] = i.first;
      //     i.second--; 
      //   }
      // }
      
      int l = 0, mid = 0, r = nums.size() - 1;
      while(mid <= r){
        if(nums[mid] == 0){
          swap(nums[l], nums[mid]);
          l++;  mid++;
        } else if (nums[mid] == 1){
          mid++;
        } else {
          swap(nums[r], nums[mid]);
          r--;
        }
      }
    }
};