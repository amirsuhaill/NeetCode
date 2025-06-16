class Solution {
public:
    // Previous Smaller Element Index
    vector<int> fxn1(vector<int> &nums, int &n) {
        vector<int> prevSmaller(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return prevSmaller;
    }

    // Next Smaller Element Index
    vector<int> fxn2(vector<int> &nums, int &n) {
        vector<int> nextSmaller(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nextSmaller;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller = fxn1(heights, n);
        vector<int> nextSmaller = fxn2(heights, n);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }
        return ans;
    }
};
