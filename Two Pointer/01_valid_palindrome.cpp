class Solution {
public:
    string to_string(string s,int &idx){
        int i = 0;
        while(i < s.size()){
            if(s[i] <= 'z' && s[i] >= 'a' || s[i] >= '0' && s[i] <= '9'){
                s[idx++] = s[i];                
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[idx++] = s[i] + 32;
            }
            i++;
        } return s;
    }

    bool isPalindrome(string s) {
        int ei = 0;
        s = to_string(s,ei);
        int si = 0;
        ei--;
        while(si <= ei){
            if(s[si++] != s[ei--]){
                return false;
            }
        }
        return true;
    }
};