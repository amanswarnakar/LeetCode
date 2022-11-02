class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> um;
      for(auto &num: nums){
        um[num]++;
        if(um[num] > 1) return true;
      }
      return false;
      
      // unordered_set<int> s;
      // for(auto &num: nums){
      //   if(!s.insert(num).second) return true;
      //   // Set.insert() returns a pair in which 
      //   // the second part of the pair is a bool
      //   // value that indicates whether the element 
      //   // has been inserted into the set or not.
      //   // Returns true if inserted, false otherwise.
      // }
      // return false;
    }
};