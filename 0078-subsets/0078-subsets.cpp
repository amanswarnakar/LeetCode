class Solution {
public:
    void recur(int idx, vector<int> &v, vector<int> &temp, vector<vector<int>> &ans){
      if(idx == v.size()) {
        ans.emplace_back(temp);
        return;
      }
      temp.emplace_back(v[idx]);
      recur(idx + 1, v, temp, ans);
      temp.pop_back();
      recur(idx + 1, v, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& v) {
      vector<vector<int>> ans;
      vector<int> temp;
      recur(0, v, temp, ans);
      return ans;
    }
};