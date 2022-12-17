class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<string> st;
      long long int ans = stoll(tokens[0]);
      for(auto &i: tokens){
        if(i == "+" or i == "-" or i == "*" or i == "/"){
          string a = st.top(); st.pop();
          string b = st.top(); st.pop();
          if(i == "+") ans = stoll(a) + stoll(b);
          else if(i == "-") ans = stoll(b) - stoll(a);
          else if(i == "*") ans = stoll(a) * stoll(b);
          else ans = stoll(b) / stoll(a);
          st.push(to_string(ans));
        } else {
          st.push(i);
        }
      }
      return int(ans);
    }
};