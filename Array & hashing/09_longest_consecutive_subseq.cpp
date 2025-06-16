class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int &x : nums){
            st.insert(x);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-1) != st.end()) continue;  // agr chota hai to skip

            int cnt = 1;
            int num = nums[i];
            while(st.find(num+1) != st.end()){  //jb tk bada mil rha hai cnt krte jao
                num++;
                cnt++;
            }
            ans = max(ans,cnt);   

        } st.clear();
        return ans;
    }
};
