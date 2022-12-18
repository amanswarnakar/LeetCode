class Solution {
public:
    int singleNumber(vector<int>& v) {
      unordered_map<int, int> um;
      for(auto &i: v){
        um[i]++;
      }
      for(auto &p: um){
        if(p.second == 1) return p.first;
      }
      return 0;
    }
};