class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char, int> um;
      for(auto &i: s){
        um[i]++;
      }
      vector<pair<int, char>> v;
      string ans = "";
      for(auto &p: um){
        v.push_back({p.second, p.first});
      }
      sort(v.begin(), v.end(), greater<>());
      for(auto &i: v){
        while(i.first--)  ans += i.second;
      }
      return ans;
    }
};