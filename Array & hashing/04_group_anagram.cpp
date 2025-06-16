class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(auto &s : strs){
            vector<int> freq(26);
            for(char &x : s){
                freq[x-'a']++;
            }
            string t = "";
            for(int i=0;i<26;i++){
                while(freq[i] > 0){
                    t += (i+'a');
                    freq[i]--;
                }
            }
            mpp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &x : mpp){
            vector<string> v;
            for(string &s : x.second){
                v.push_back(s);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
