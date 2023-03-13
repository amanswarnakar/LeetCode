class Solution {
public:
    int maxScore(vector<int>& v) {
      int n = v.size();
      sort(v.begin(), v.end(), greater<int>());
      int ans = 0, i = 0;
      long long int sum = 0;
      while(i < n and sum + v[i] > 0){
        sum += v[i++];
        ans++;
      }
      return ans;
    }
  /*
      int n = v.size();
      sort(v.begin(), v.end());
      vector<int> pos, neg;
      for(auto &i: v){
        if(i > 0) pos.emplace_back(i);
        else neg.emplace_back(i);
      }
      long long int sum = accumulate(pos.begin(), pos.end(), 0ll);
      int ans = pos.size();
      if(ans) ans += n - pos.size() - neg.size();
      int x = neg.size() - 1;
      while(x >= 0 and sum > 0){
        sum += neg[x--];
        if(sum > 0)
          ans++;
      }
      return ans;
  */
};