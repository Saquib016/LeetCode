class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            if(s[i]=='(' || s[i] == '['|| s[i] == '{')
                st.push(c);
            else {
                if(st.empty()) return false;
                if(c==')' && st.top()!='(') return false;
                if(c==']' && st.top()!='[') return false;
                if(c=='}' && st.top()!='{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};