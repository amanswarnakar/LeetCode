class Solution {
public:
    void recur(int i, int n, vector<int> &temp, vector<int> &v, set<vector<int>> &ans){
      if(i == n){
        sort(temp.begin(), temp.end());
        ans.insert(temp);
        return;
      }
      temp.emplace_back(v[i]);
      recur(i + 1, n, temp, v, ans);
      temp.pop_back();
      recur(i + 1, n, temp, v, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
      int n = v.size();
      sort(v.begin(), v.end());
      set<vector<int>> st;
      vector<vector<int>> ans;
      vector<int> temp;
      recur(0, n, temp, v, st);
      for(auto &i: st) ans.emplace_back(i);
      return ans;
    }
};