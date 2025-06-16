class Solution {
public:

    int search(vector<int>& nums, int target) {
        int si = 0, ei = nums.size()-1;
        int mid;

        while(si <= ei){
            mid = si + (ei-si)/2;

            if(nums[mid] == target) return mid;

            if(nums[mid] < target) si = mid+1;
            else ei = mid-1;
        }
        return -1;
    }
};
