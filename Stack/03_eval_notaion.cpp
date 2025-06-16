class Solution {
public:
    bool isOP(string &s){
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int eval(int &val1,int &val2,string &op){
        if(op == "+") return val1+val2;
        if(op == "-") return val2-val1;
        if(op == "/") return val2/val1;
        if(op == "*") return val1*val2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto &s: tokens){
            if(!isOP(s)){
                int val = stoi(s);
                st.push(val);
            }
            else{
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                st.push(eval(val1,val2,s));
            }
        }
        return st.top();
    }
};
