class Solution {
public:
    string decToBin(int n, int sz){
      string res = "";
      while(n){
        res = to_string(n % 2) + res;
        n /= 2;
      }
      while(res.size() != sz) res = "0" + res;
      return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
      unordered_map<int, int> um;
      for(auto &i: nums){
        um[stoi(i, 0, 2)]++;
      }
      string res = "";
      for(int i = 0; i < nums.size(); i++) res += "0";
      if(!um.count(0)) return res;
      for(int i = 1; i < pow(2, nums.size()); i++)
        if(!um.count(i)) return decToBin(i, nums.size());
      return "";
      
      // int n = nums.size();
      // string res = "";
      // for(int i = 0; i < n; i++){
      //   if(nums[i][i] == '1') res += "0";
      //   else res += "1";
      // }
      // return res;
    }
};