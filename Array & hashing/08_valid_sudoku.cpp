class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                
                string s1 = string(1,board[i][j]) + "r" + to_string(i);
                if (st.find(s1) != st.end()) return false;

                string s2 = string(1,board[i][j]) + "c" + to_string(j);
                if (st.find(s2) != st.end()) return false;

                string s3 = string(1,board[i][j]) + "b" + to_string(i / 3) + to_string(j / 3);
                if (st.find(s3) != st.end()) return false;

                st.insert(s1);
                st.insert(s2);
                st.insert(s3);                
            }
        }
        return true;
    }
};