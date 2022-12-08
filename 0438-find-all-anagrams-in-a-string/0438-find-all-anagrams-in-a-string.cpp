class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> v1(26), v2(26), ans;
      for(int i = 0; i < p.size(); i++){
        v1[p[i] - 'a']++;
      }
      int l = 0, r = 0, n = s.size();
      while(r < n){
        v2[s[r] - 'a']++;
        if(r - l + 1 == p.size() and v1 == v2) ans.emplace_back(l);
        if(r - l + 1 < p.size()) r++;
        else {
          v2[s[l] - 'a']--; l++; r++;
        }
      }
      return ans;
    }
};