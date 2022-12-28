class Solution {
public:
    string helper(string s){
      string res = "";
      stack<char> st;
      for(auto &ch: s){
        if(ch != '#') st.push(ch);
        else if(st.size()) st.pop();
      }
      while(!st.empty()){
        res += st.top();
        st.pop(); 
      }
      return res;
    }
    bool backspaceCompare(string s, string t) {
      return helper(s) == helper(t);
    }
};