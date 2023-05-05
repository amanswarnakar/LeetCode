class Solution {
public:
    string predictPartyVictory(string s) {
      queue<int> r, d;
      int n = s.size();
      for(int i = 0; i < n; i++){
        s[i] == 'R' ? r.emplace(i) : d.emplace(i);
      }
      while(!r.empty() and !d.empty()){
        int rid = r.front(), did = d.front();
        r.pop(); d.pop();
        (rid < did) ? r.emplace(rid + n) : d.emplace(did + n);
      }
      return r.size() > d.size() ? "Radiant" : "Dire";
    }
};