class Solution {
public:
    static bool comp(pair<int, string> a, pair<int, string> b){
      if(a.first > b.first) return true;
      else if(a.first == b.first and a.second < b.second) return true;
      return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
      map<string, int> mp;
      for(string s : words){
        mp[s]++;
      }
      vector<pair<int, string>> v;
      for(pair<string, int> p : mp){
        v.push_back({p.second, p.first});
      }
      sort(v.begin(), v.end(), comp);
      // for(auto i : v){
        // cout<<i.first<<"~"<<i.second<<endl;
      // }
      vector<string> ans;
      for(int i = 0; i < k; i++){
        ans.push_back(v[i].second);
      }
      return ans;
    }
};