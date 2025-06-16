class Solution {
public:
    void solve(string &str,int &n,vector<string> &ans,int &open, int &close){
        if(open > n || close > n || close > open) return;

        if(str.size() == 2*n){
            ans.push_back(str);
            return;
        }

        str.push_back('(');
        open++;
        solve(str,n,ans,open,close);
        str.pop_back();
        open--;

        str.push_back(')');
        close++;
        solve(str,n,ans,open,close);
        str.pop_back();
        close--;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int open = 0, close = 0;

        solve(s,n,ans,open,close);

        return ans;
    }
};