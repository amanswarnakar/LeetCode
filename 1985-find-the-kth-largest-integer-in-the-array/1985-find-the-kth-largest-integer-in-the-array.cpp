class Solution {
public:
    static bool comp (string a, string b){
      int m = a.size(), n = b.size();
      if(m < n) return true;
      else if(m > n) return false;
      for(int i = 0; i < min(m, n); i++){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
      }
      return false;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
      sort(nums.begin(), nums.end(), comp);
      int n = nums.size();
      // for(auto i : nums) cout<<i<<" ";
      return nums[n - k];
    }
};