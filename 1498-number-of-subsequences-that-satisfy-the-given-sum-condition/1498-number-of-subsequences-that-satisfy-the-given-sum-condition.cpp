class Solution {
public:
    int numSubseq(vector<int>& v, int k) {
      sort(v.begin(), v.end());
      long long int ans = 0, n = v.size(), mod = 1e9+7;
      vector<int> power(n, 1);
      for(int i = 1; i < n; i++){
        power[i] = (power[i - 1] * 2) % mod;
      }
      for(int i = 0; i < n; i++){
        auto it = upper_bound(v.begin(), v.end(), k - v[i]) - v.begin();
        if(it > 0 and it > i and v[i] + v[it - 1] <= k){
          ans += power[it - i - 1] % mod;
          ans %= mod;
        }
      }
      return ans;
    }
};