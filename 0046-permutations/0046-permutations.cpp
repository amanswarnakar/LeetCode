class Solution {
public:
    void helper(vector<int> &v, vector<bool> &vis, vector<int> &temp, vector<vector<int>> &ans){
      if(temp.size() == v.size())
        ans.emplace_back(temp);
      for(int i = 0; i < v.size(); i++){
        if(!vis[i]){
          vis[i] = true;
          temp.emplace_back(v[i]);
          helper(v, vis, temp, ans);
          temp.pop_back();
          vis[i] = false;
        }
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      int n = nums.size(); 
      vector<bool> vis(n, false);
      vector<int> temp;
      vector<vector<int>> ans;
      helper(nums, vis, temp, ans);
      return ans;
    }
};