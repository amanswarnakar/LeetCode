class Solution {
public:
    vector<int> successfulPairs(vector<int>& v, vector<int>& p, long long t) {
      int n = v.size(), m = p.size();
      sort(p.begin(), p.end());
      vector<int> ans(n);
      for(int i = 0; i < n; i++){
        auto idx = lower_bound(begin(p), end(p), (long long)(t + v[i] - 1) / v[i]) - p.begin();
        ans[i] = m - idx;
      }
      return ans;
    }
};