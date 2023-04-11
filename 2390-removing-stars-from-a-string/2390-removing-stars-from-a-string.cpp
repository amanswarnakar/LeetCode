class Solution {
public:
    string removeStars(string s) {
      // Two Pointer Solution
      
      int i = 0, j = 0, n = s.size();
      for(int i = 0; i < n; i++){
        if(s[i] == '*') j--;
        else s[j++] = s[i];
      }
      s.resize(j);
      return s;
      
      
      
      // String Solution
      
      // string ans = "";
      // for(auto &i: s){
      //   if(i == '*') ans.pop_back();
      //   else ans.push_back(i);
      // }
      // return ans;
      
      
      // Stack Solution
      
      // stack<char> st;
      // for(auto &i: s){
      //   if(i == '*') st.pop();
      //   else st.push(i);
      // }
      // string ans = "";
      // int sz = st.size();
      // while(sz--){
      //   ans.push_back(st.top());
      //   st.pop();
      // }
      // reverse(ans.begin(), ans.end());
      // return ans;
    }
};