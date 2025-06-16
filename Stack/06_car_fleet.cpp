class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();

        vector<vector<int>> pair(n,vector<int> (2));

        for(int i=0;i<n;i++){
            pair[i][0] = target - position[i];
            pair[i][1] = speed[i];
        }

        sort(pair.begin(),pair.end(),[](vector<int> &a,vector<int> &b){
            return a[0] >= b[0];
        });


        vector<double> time(n);
        for(int i=0;i<n;i++){
            time[i] = (double)pair[i][0]/pair[i][1];
        }

        int ans = 1;

        stack<double> st;

        st.push(time[n-1]);

        for(int i=n-2;i>=0;i--){
            if(st.top() < time[i]){
                while(!st.empty()){
                    st.pop();
                }
                st.push(time[i]);
                ans++;
            }
        }

        return ans;
    }
};