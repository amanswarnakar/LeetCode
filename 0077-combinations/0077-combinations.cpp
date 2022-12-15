class Solution {
public:
    void helper(int idx, int k, int n, vector<int> &temp, vector<vector<int>> &ans){
      if(temp.size() == k){
        ans.emplace_back(temp);
        return;
      }
      for(int i = idx; i <= n; i++){
        temp.emplace_back(i);
        helper(i + 1, k, n, temp, ans);
        temp.pop_back();
      }
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> ans;
      vector<int> temp;
      helper(1, k, n, temp, ans);
      return ans;
    }
};