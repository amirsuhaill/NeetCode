class Solution {
public:
//              OPTIMAL O(log(min(n,m)))
    double fxn(vector<int> &nums1,vector<int> &nums2){
        int n = nums1.size(), m = nums2.size();
        int l = 0, r = n;

        while(l <= r){
            int px = l + (r-l)/2;
            int py = (n+m+1)/2 - px;

            //left half
            int x1 = (px == 0) ? INT_MIN : nums1[px-1];
            int x2 = (py == 0) ? INT_MIN : nums2[py-1];


            //right half
            int x3 = (px == n) ? INT_MAX : nums1[px];
            int x4 = (py == m) ? INT_MAX : nums2[py];

            if(x1 <= x4 && x2 <= x3){
                if((m+n)%2 == 1){
                    return max(x1,x2);
                }else{
                    return (max(x1,x2)+min(x3,x4))/2.0;
                }
            }

            if(x1 > x4){
                r = px-1;
            }else{
                l = px+1;
            }
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) return fxn(nums1,nums2);
        return fxn(nums2,nums1);
    }
};