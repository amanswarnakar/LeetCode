class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first; 
    }
    int bestTeamScore(vector<int>& s, vector<int>& a) {
      int n = s.size();
      vector<pair<int, int>> v;
      for(int i = 0; i < n; i++){
        v.emplace_back(make_pair(a[i], s[i]));
      }
      sort(v.begin(), v.end());
      // for(auto &[a, b]: v) cout<<a<<" "<<b<<endl;
      int ans = 0;
      vector<int> dp(n, 0);
      for(int i = 0; i < n; i++){
        dp[i] = v[i].second;
        ans = max(ans, dp[i]);
      }
      for(int i = 0; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
          if(v[i].second >= v[j].second)
            dp[i] = max(dp[i], v[i].second + dp[j]);
        }
        ans = max(ans, dp[i]);
      }
      return ans;
    }
};