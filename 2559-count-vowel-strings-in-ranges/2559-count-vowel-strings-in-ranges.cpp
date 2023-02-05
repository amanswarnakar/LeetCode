class Solution {
public:
    int helper(string s){
      int n = s.size();
      if((s[0] == 'a' or s[0] == 'e' or s[0] == 'i' or s[0] == 'o' or s[0] == 'u') and (s[n - 1] == 'a' or s[n - 1] == 'e' or s[n - 1] == 'i' or s[n - 1] == 'o' or s[n - 1] == 'u'))
        return 1;
      return 0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
      int n = words.size();
      vector<int> v(n, 0);
      for(int i = 0; i < n; i++){
        v[i] = helper(words[i]);
      }
      vector<int> psum(n, v[0]);
      for(int i = 1; i < n; i++){
        psum[i] = v[i] + psum[i - 1];
      }
      vector<int> ans(q.size(), 0);
      for(int i = 0; i < q.size(); i++){
        int l = q[i][0], r = q[i][1];
        if(!v[l] and !v[r]){
          ans[i] = psum[r] - psum[l];
        } else if(!v[l]){
          ans[i] = psum[r] - psum[l];
        } else if(!v[r]){
          ans[i] = psum[r] - psum[l] + 1;
        } else {
          ans[i] = psum[r] - psum[l] + 1;
        }
      }
      return ans;
    }
};