class Solution {
public:
    vector<pair<int, int>> helper1(string s){
      vector<pair<int, int>> v(0);
      for(int i = 0; i < s.size(); i++){
        int j = i;
        while(s[i] == s[i+1]) i++;
        v.push_back({s[i] - '0', i - j + 1});
      }
      return v;
    }
    string helper2(vector<pair<int, int>> v){
      string s = "";
      for(int i = 0; i < v.size(); i++){
        s += '0' + v[i].second;
        s += '0' + v[i].first;
      }
      return s;
    }
    string countAndSay(int n) {
      vector<pair<int, int>> v;
      string ans = "1";
      for(int i = 1; i < n; i++){
        v = helper1(ans);
        ans = helper2(v);
      }
      return ans;
    }
};