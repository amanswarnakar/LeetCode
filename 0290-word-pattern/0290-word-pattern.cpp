class Solution {
public:
    bool wordPattern(string p, string s) {
      vector<string> v;
      int j = 0;
      unordered_map<char, string> cts;
      unordered_map<string, char> stc;
      for(int i = 0; i < s.size(); i++){
        string temp = "";
        while(i < s.size() and s[i] != ' '){
          temp += s[i];
          i++;
        }
        v.emplace_back(temp);
      }
      if(v.size() != p.size()) return false;
      // for(auto &i: v) cout<<i<<"~";
      for(int i = 0; i < p.size(); i++){
        if(cts.count(p[i]) and cts[p[i]] != v[i]) return false;
        if(stc.count(v[i]) and stc[v[i]] != p[i]) return false;
        stc[v[i]] = p[i];
        cts[p[i]] = v[i];
      }
      return true;
    }
};