class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
      int n = v.size(), l = 0, r = n - 1, ans = 0;
      sort(v.begin(), v.end());
      while(l <= r){
        ans++;
        if(v[l] + v[r] <= limit) l++;
        r--;
      }
      return ans;
    }
};