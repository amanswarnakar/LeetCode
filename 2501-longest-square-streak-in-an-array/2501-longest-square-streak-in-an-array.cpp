class Solution {
public:
    int longestSquareStreak(vector<int>& v) {
      int n = v.size(), idx = 0;
      map<int, int> mp;
      for(auto &i: v) mp[i]++;
      vector<pair<int, int>> ans(n);
      double maxele = *max_element(v.begin(), v.end());
      maxele = sqrt(maxele);
      for(auto &p: mp){
        ans[idx].first = p.first;
        ans[idx].second = 1;
        long long t = p.first;
        while(t <= maxele and mp.find(t * t) != mp.end()){
          t = t * t;
          ans[idx].second++;
        }
        idx++;
      }
      int res = INT_MIN;
      for(auto &p: ans){
        res = max(res, p.second);
      }
      return res == 1 ? -1 : res;
    }
};