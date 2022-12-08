class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      /*
       if (s1.size() > s2.size()) return {};
        vector<int> s1v (26, 0), ans;
        for (auto c : s1) s1v[c - 'a']++;
        vector<int> s2v (26, 0);
        int l = 0, r = 0;
        while (r < s2.size()) {
            s2v[s2[r]-'a']++;
            if (r - l + 1 == s1.size()) 
                if (s1v == s2v) ans.emplace_back(l);
            if (r - l + 1 < s1.size()) r++;
            else {
                s2v[s2[l]-'a']--;
                l++;
                r++;
            }
        }
        return ans;
      */
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