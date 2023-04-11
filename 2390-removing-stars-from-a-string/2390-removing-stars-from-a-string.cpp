class Solution {
public:
    string removeStars(string s) {
      // String Solution
      string ans = "";
      for(auto &i: s){
        if(i == '*') ans.pop_back();
        else ans.push_back(i);
      }
      return ans;
        
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