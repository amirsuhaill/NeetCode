class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pro = 1;
        int zero = 0;
        for(int &x : nums){
            if(x != 0) pro *= x;
            else zero++;
        }
        for(int i=0;i<nums.size();i++){
            if(zero == 0){
                nums[i] = pro/nums[i];
            }
            else if(zero == 1){
                if(nums[i] == 0) nums[i] = pro;
                else nums[i] = 0;
            }
            else {
                nums[i] = 0;
            }
        }
        return nums;
    }
};
