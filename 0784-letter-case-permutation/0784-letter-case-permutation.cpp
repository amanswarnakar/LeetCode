class Solution {
public:
    vector<string> letterCasePermutation(string s) {
      // BFS Approach
      
      vector<string> ans;
      queue<string> q{{""}};
      for(int k = 0; k < s.size(); k++){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
          string top = q.front(); q.pop();
          if(isalpha(s[k])){
            q.emplace(top + string(1, tolower(s[k])));
            q.emplace(top + string(1, toupper(s[k])));
          } else q.emplace(top + s[k]);
        }
      }
      while(!q.empty()){
        ans.emplace_back(q.front());
        q.pop();
      }
      return ans;
    }
};