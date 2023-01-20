class Solution {
public:
    void helper(int i, vector<int> &v, vector<int> &temp, set<vector<int>> &ans){
      int n = v.size();
      if(i >= n){
        if(temp.size() > 1){
          ans.insert(temp);
        }
        return;
      }
      if(!temp.size() or temp.back() <= v[i]){
        temp.emplace_back(v[i]);
        helper(i + 1, v, temp, ans);
        temp.pop_back();
      }
      helper(i + 1, v, temp, ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      vector<int> temp;
      set<vector<int>> ans;
      helper(0, nums, temp, ans);
      return vector(ans.begin(), ans.end());
    }
};