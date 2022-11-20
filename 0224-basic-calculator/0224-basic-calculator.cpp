class Solution {
public:
    int calculate(string s) {
      int ans = 0, sum = 0, sign = 1, n = s.size();
      stack<int> st;
      for(int i = 0; i < n; i++){
        if(isdigit(s[i])){
          sum = s[i] - '0';
          while(i+1 < n and isdigit(s[i+1])){
            sum = sum * 10 + (s[i+1] - '0');
            i++;
          }
          ans += sum * sign;
        } else if(s[i] == '+'){
          sign = 1;
        } else if(s[i] == '-'){
          sign = -1;
        } else if(s[i] == '('){
          st.push(ans);
          st.push(sign);
          sign = 1;
          ans = 0;
        } else if(s[i] == ')'){
          int stSign = st.top();
          st.pop();
          int stAns = st.top();
          st.pop();
          ans = ans * stSign + stAns;
        }
      }
      return ans;
    }
};