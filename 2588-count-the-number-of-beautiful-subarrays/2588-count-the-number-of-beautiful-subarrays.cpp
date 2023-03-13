class Solution {
public:
    long long beautifulSubarrays(vector<int>& v) {
      long long int ans = 0, xr = 0, n = v.size();
      map<int, long long int> mp;
      mp[0]++;
      for(int i = 0; i < n; i++){
        xr ^= v[i];
        if(mp.count(xr)) ans += mp[xr];
        mp[xr]++;
      }
      return ans;
    }
};