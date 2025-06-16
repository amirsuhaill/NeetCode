class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int &x : nums){
            if(s.find(x) != s.end()) return true;
            s.insert(x);
        }s.clear();
        return false;
    }
};