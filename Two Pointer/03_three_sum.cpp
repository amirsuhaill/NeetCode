class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<nums.size()-1;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int si = i+1, ei = nums.size()-1;
            int target = -nums[i];

            while(si < ei){
                while(nums[si] == nums[si+1] && si+1 < ei) si++;
                while(nums[ei] == nums[ei-1] && ei-1 > si) ei--;

                if(nums[si] + nums[ei] == target){
                    ans.push_back({-target,nums[si],nums[ei]});
                    si++; ei--;
                }
                else if(nums[si] + nums[ei] < target){
                    si++;
                }else ei--;
            }
        }

        return ans;
    }
};
