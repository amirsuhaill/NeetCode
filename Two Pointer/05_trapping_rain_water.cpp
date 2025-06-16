class Solution {
public:
    vector<int> getLeftMax(vector<int> &height,int n){
        vector<int> lmx(n);
        lmx[0] = height[0];
        
        for(int i=1;i<n;i++){
            lmx[i] = max(height[i],lmx[i-1]);
        }
        return lmx;
    }
    vector<int> getRightMax(vector<int> &height,int n){
        vector<int> rmx(n);
        rmx[n-1] = height[n-1];
        
        for(int i=n-2;i>=0;i--){
            rmx[i] = max(rmx[i+1],height[i]);
        }
        return rmx;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmx = getLeftMax(height,n);
        vector<int> rmx = getRightMax(height,n);

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (min(lmx[i],rmx[i])-height[i]);
        } return ans;
    }
};
