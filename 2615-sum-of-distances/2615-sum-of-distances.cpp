class Solution {
public:
    vector<long long> distance(vector<int>& v) {
      int n = v.size();
      vector<long long> ans(n, 0);
      unordered_map<long long, long long> sum, cnt;
      for(int i = 0; i < n; i++){
        ans[i] += cnt[v[i]] * i - sum[v[i]];
        sum[v[i]] += i;
        cnt[v[i]]++;
      }
      sum.clear(); cnt.clear();
      for(int i = n - 1; i >= 0; i--){
        ans[i] += - cnt[v[i]] * i + sum[v[i]];
        sum[v[i]] += i;
        cnt[v[i]]++;
      }
      return ans;
    }
};

/*
    
    1 3 1 1 2
    1 4 5 6 8
    0 - 2 3 -
*/