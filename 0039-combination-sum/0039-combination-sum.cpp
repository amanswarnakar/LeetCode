class Solution {
public:
    void recur(int idx, vector<int> &v, vector<int> &temp, vector<vector<int>> &ans, int t){
      if(t == 0){
        sort(begin(temp), end(temp));
        ans.emplace_back(temp);
        return;
      }
      while(idx < v.size() and t - v[idx] >= 0){
        temp.emplace_back(v[idx]);
        recur(idx, v, temp, ans, t - v[idx]);
        idx++;
        temp.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
      vector<vector<int>> ans;
      vector<int> temp;
      sort(begin(v), end(v));
      v.erase(unique(begin(v), end(v)), end(v));
      recur(0, v, temp, ans, t);
      return ans;
    }
};