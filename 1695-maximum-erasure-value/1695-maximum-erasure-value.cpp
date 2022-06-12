class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
      int n = a.size(), l = 0, r = 0;
      map<int, int> mp;
      int sum = 0;
      int ans = 0;
      while(r < n){
        sum += a[r];
        mp[a[r]]++;
          while(mp[a[r]] > 1){
            sum -= a[l];
            mp[a[l]]--;
            l++;
          }
        ans = max(ans, sum);
        r++;
      }
      return ans;
    }
};