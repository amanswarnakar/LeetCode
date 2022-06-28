// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      // TLE - Brute Force (Linear Search)
      
      // int l = 1;
      // while(l <= n){
      //   if(!isBadVersion(l))  l++;
      //   else break;
      // }
      // return l;
      
      
      // Binary Search
      
      int l = 1, r = n;
      while(l < r){
        int mid = l + (r-l)/2;
        if(isBadVersion(mid)) r = mid;
        else l = mid + 1;
      }
      return r;
    }
};