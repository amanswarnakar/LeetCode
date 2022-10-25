class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {
      string p = "", q = "";
      for(auto s : a){
        p += s;
      }
      for(auto s : b){
        q += s;
      }
      return p == q;
    }
};