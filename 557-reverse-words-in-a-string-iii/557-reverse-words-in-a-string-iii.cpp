class Solution {
public:
      // Two Pointer Approach
    // string reverse(string s){
    //   int l = 0, r = s.size() - 1;
    //   while(l < r) swap(s[l++], s[r--]);
    //   return s;
    // }
  
    string reverseWords(string s) {
      // string ans = "";
      // for(int i = 0; i < s.size(); i++){
      //   string temp = "";
      //   while(i < s.size() and s[i] != ' ') temp += s[i++];
      //   ans += reverse(temp);
      //   if(i != s.size())
      //     ans += ' ';
      //   // cout<<temp<<" ~ "<<ans<<"\n";
      // }
      // return ans;
      
      int n = s.size(), j = 0;
      for(int i = 0; i <= n; i++){
        if(s[i] == ' ' or s[i] == '\0'){
          reverse(s.begin() + j, s.begin() + i);
          j = i + 1;
        }
      }
      return s;
    }
};