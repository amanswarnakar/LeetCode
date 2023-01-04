class Solution {
public:
    int minimumRounds(vector<int>& v) {
      unordered_map<int, int> um;
      for(auto &i: v){
        um[i]++;
      }
      int ans = 0;
      for(auto &[f, s]: um){
        if(s < 2) return -1;
        else{
          if(s % 3 == 0) ans += s / 3;
          else ans += s / 3 + 1;
        }
      }
      return ans;
    }
};