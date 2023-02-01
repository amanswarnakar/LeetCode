class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      if(str1 + str2 != str2 + str1) return "";
      int x = gcd(str1.size(), str2.size());
      return str1.substr(0, x);
    }
  
  /*
  bool valid(string s, string p, int k){
      int m = s.size(), n = p.size();
      if(m % k > 0 or n % k > 0){
        return false;
      } else {
        string temp = s.substr(0, k);
        int n1 = m / k, n2 = n / k;
        return s == joinWords(temp, n1) and p == joinWords(temp, n2);
      }
    }
    string joinWords(string s, int k){
      string res = "";
      for(int i = 0; i < k; i++)
        res += s;
      return res;
    }
    string gcdOfStrings(string str1, string str2) {
      int m = str1.size(), n = str2.size();
      for(int i = min(m, n); i >= 1; i--){
        if(valid(str1, str2, i))
          return str1.substr(0, i);
      }
      return "";
    }
  */
};