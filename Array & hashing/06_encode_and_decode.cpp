class Solution {
public:

    string encode(vector<string>& strs) {
        string coded;
        for(int i=0;i<strs.size();i++){
            coded += (strs[i] + ":;");
        }
        return coded;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        while(i < s.size()){
            string temp = "";
            while(i < s.size() && !(s[i] == ':' && s[i + 1] == ';')) {
                temp += s[i];
                i++;
            }
            ans.push_back(temp);
            i += 2;
        }
        return ans;
    }
};
