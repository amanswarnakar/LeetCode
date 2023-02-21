class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
      map<int, int> mp;
      for(auto &i: v){
        mp[i]++;
      }
      for(auto &[f, s]: mp){
        if(s == 1) return f;
      }
      return 0;
    }
};