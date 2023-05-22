class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
      return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& v, int k) {
      unordered_map<int, int> um;
      for(auto &i: v) um[i]++;
      vector<pair<int, int>> vp;
      for(auto &i: um){
        vp.emplace_back(i);
      }
      sort(vp.begin(), vp.end(), comp);
      vector<int> ans;
      int n = v.size();
      for(int i = 0; i < k; i++){
        if(ans.emplace_back(vp[i].first));
      }
      return ans;
    }
};