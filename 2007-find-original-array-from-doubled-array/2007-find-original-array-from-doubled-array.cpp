class Solution {
public:
       vector<int> findOriginalArray(vector<int> &changed) {
        if (changed.size() % 2) return {};
        unordered_map<int, int> mp;
        for (int a : changed) mp[a]++;
        vector<int> v, ans;
        for (auto it : mp)
            v.push_back(it.first);
        sort(v.begin(), v.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int x : v) {
          // cout<<x<<" ";
            if (mp[x] > mp[2 * x]) return {};
            for (int i = 0; i < mp[x]; ++i, mp[2 * x]--)
                ans.push_back(x);
        }
        return ans;
    }
};