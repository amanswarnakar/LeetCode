class Solution {
public:
    void recur(int idx, vector<int> &v, vector<int> &temp, vector<vector<int>> &ans, set<vector<int>> &st){
      int n = v.size();
      if(idx == n) {
        ans.emplace_back(temp);
        st.insert(temp);
        return;
      }
      temp.emplace_back(v[idx]);
      recur(idx + 1, v, temp, ans, st);
      temp.pop_back();
      recur(idx + 1, v, temp, ans, st);
    }
    vector<vector<int>> subsets(vector<int>& v) {
      vector<vector<int>> ans;
      vector<int> temp;
      set<vector<int>> st;
      recur(0, v, temp, ans, st);
      return ans;
    }
};