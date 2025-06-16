class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int ans = 0;
        while(i < j){
            ans = max(ans,(j-i)*min(heights[i],heights[j]));
            if(heights[i] > heights[j]) j--;
            else i++;
        } 
        return ans;
    }
};
