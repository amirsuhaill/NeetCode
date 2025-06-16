class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k) return nums;

        unordered_map<int,int> mpp;
        for(int &x : nums){
            mpp[x]++;
        }
        vector<vector<int>> redix(n+1);

        for(auto &x : mpp){
            int ele = x.first;
            int freq = x.second;

            redix[freq].push_back(ele);
        }

        vector<int> ans(k);
        int idx = 0;
        for(int i=n;i>=0;i--){
            if(idx == k) break;
            if(redix[i].size()){
                for(int &ele : redix[i]){
                    ans[idx++] = ele;
                }
            }
        }

        return ans;
    }
};
